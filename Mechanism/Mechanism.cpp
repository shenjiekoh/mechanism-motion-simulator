#include "Mechanism.h"
#include <cmath>

Mechanisms::Mechanisms(const double w, const double a) :omega(w), alpha(a) {};

FourBar::FourBar(double* r_arr, double* c, const double w, const double a) :Mechanisms(w, a)
{
	for (int i = 0; i < 4; i++)
		r[i] = r_arr[i];
	coupler[0] = c[0];
	coupler[1] = c[1];
	double r_copy[4] = { r[0],r[1],r[2],r[3] };
	for (int i = 0; i < 3; i++)
	{
		double min = r_copy[i];
		for (int j = i + 1; j < 4; j++)
			if (r_copy[j] < min)
			{
				double temp = r_copy[i];
				r_copy[i] = r_copy[j];
				r_copy[j] = temp;
				min = r_copy[i];
			}
	}
	double s = r_copy[0];
	double p = r_copy[1];
	double q = r_copy[2];
	double l = r_copy[3];
	if (s == r[2] && s + l < p + q || s + l > p + q)
		fullRotation = false;
	else
		fullRotation = true;
}

void FourBar::Velocity(double* dst, double* theta)
{
	// theta = {theta2, theta3, theta4}
	dst[0] = r[1] * Omega() / r[2] * (sin(theta[0] - theta[2]) / sin(theta[2] - theta[1]));	// theta3d
	dst[1] = r[1] * Omega() / r[3] * (sin(theta[0] - theta[1]) / sin(theta[2] - theta[1]));	// theta4d
}

void FourBar::Acceleration(double* dst, double* theta, double* thetad)
{
	// theta = {theta2, theta3, theta4}
	// thetad = {theta3d, theta4d}
	dst[0] = (-r[1] * pow(Omega(), 2) * cos(theta[0] - theta[2]) - r[1] * Alpha() * sin(theta[0] - theta[2])
		- r[2] * pow(thetad[0], 2) * cos(theta[1] - theta[2])
		+ r[3] * pow(thetad[1], 2)) / (r[2] * sin(theta[1] - theta[2]));	// theta3dd
	dst[1] = (-r[1] * pow(Omega(), 2) * cos(theta[0] - theta[1]) - r[1] * Alpha() * sin(theta[0] - theta[1])
		- r[2] * pow(thetad[0], 2) + r[3] * pow(thetad[1], 2) * cos(theta[1] - theta[2]))
		/ (r[3] * sin(theta[1] - theta[2]));	// theta4dd
}

void FourBar::couplerPointVelocity(double* dst, double* theta, double* thetad)
{
	// theta = {theta2, theta3, theta4}
	// thetad = {theta3d, theta4d}
	dst[0] = -r[1] * Omega() * sin(theta[0]) - 
		thetad[0] * (coupler[0] * sin(theta[1]) + coupler[1] * cos(theta[1]));	// xcd
	dst[1] = r[1] * Omega() * cos(theta[0]) +
		thetad[0] * (coupler[0] * cos(theta[1]) - coupler[1] * sin(theta[1]));	// ycd
}

void FourBar::couplerPointAcceleration(double* dst, double* theta, double* thetad, double* thetadd)
{
	// theta = {theta2, theta3, theta4}
	// thetad = {theta3d, theta4d}
	// thetadd = {theta3dd, theta4dd}
	dst[0] = -r[1] * pow(Omega(), 2) * cos(theta[0]) - r[1] * Alpha() * sin(theta[0])
		- pow(thetad[0], 2) * (coupler[0] * cos(theta[1]) - coupler[1] * sin(theta[1]))
		- thetadd[0] * (coupler[0] * sin(theta[1]) + coupler[1] * cos(theta[1]));	// xcdd
	dst[1] = -r[1] * pow(Omega(), 2) * sin(theta[0]) + r[1] * Alpha() * cos(theta[0])
		- pow(thetad[0], 2) * (coupler[0] * sin(theta[1]) + coupler[1] * cos(theta[1]))
		+ thetadd[0] * (coupler[0] * cos(theta[1]) - coupler[1] * sin(theta[1]));	// ycdd
}

SliderCrank::SliderCrank(double* r_arr, double* c, const double w, const double a) :Mechanisms(w, a)
{
	for (int i = 0; i < 3; i++)
		r[i] = r_arr[i];
	coupler[0] = c[0];
	coupler[1] = c[1];
}

void SliderCrank::Velocity(double* dst, double* theta)
{
	// theta = {theta2, theta3}
	dst[0] = r[1] * Omega() * sin(theta[1] - theta[0]) / cos(theta[1]);	// r4d
	dst[1] = r[1] * Omega() * cos(theta[0]) / (r[2] * cos(theta[1]));	// theta3d
}

void SliderCrank::Acceleration(double* dst, double* theta, double* thetad)
{
	// theta = {theta2, theta3}
	// thetad = {theta2d, theta3d}
	dst[0] = (-r[1] * pow(thetad[0], 2) * cos(theta[1] - theta[0]) + 
		r[1] * Alpha() * sin(theta[1] - theta[0]) + r[2] * pow(thetad[1], 2)) / cos(theta[1]);	// r4dd
	dst[1] = (-r[1] * pow(thetad[0], 2) * sin(theta[0]) + r[1] * Alpha() * cos(theta[0])
		+ r[2] * pow(thetad[1], 2) * sin(theta[1])) / (r[2] * cos(theta[1]));	// theta3dd
}

double SliderCrank::stroke()
{
	double s1 = sqrt(pow(r[1] + r[2], 2) - pow(r[0], 2));
	double s2 = sqrt(pow(r[2] - r[1], 2) - pow(r[0], 2));
	return s1 - s2;
}

double SliderCrank::time_ratio()
{
	double alpha1 = asin(r[0] / (r[1] + r[2]));
	double alpha2 = asin(r[0] / (r[2] - r[1]));
	const double PI = atan(1.0) * 4;
	double delta = PI + alpha2 - alpha1;
	return delta / (2 * PI - delta);
}

void SliderCrank::couplerPointVelocity(double* dst, double* theta, double theta3d)
{
	// theta = {theta2, theta3}
	dst[0] = -r[1] * Omega() * sin(theta[0]) + theta3d * (coupler[0] * sin(theta[1]) + coupler[1] * cos(theta[1]));	// xcd
	dst[1] = r[1] * Omega() * cos(theta[0]) - theta3d * (coupler[0] * cos(theta[1]) - coupler[1] * sin(theta[1]));	// ycd
}

void SliderCrank::couplerPointAcceleration(double* dst, double* theta, double theta3d, double theta3dd)
{
	// theta = {theta2, theta3}
	dst[0] = -r[1] * pow(Omega(), 2) * cos(theta[0]) - r[1] * Alpha() * sin(theta[0])
		+ pow(theta3d, 2) * (coupler[0] * cos(theta[1]) - coupler[1] * sin(theta[1]))
		+ theta3dd * (coupler[0] * sin(theta[1]) + coupler[1] * cos(theta[1]));	// xcdd
	dst[1] = -r[1] * pow(Omega(), 2) * sin(theta[0]) + r[1] * Alpha() * cos(theta[0])
		+ pow(theta3d, 2) * (coupler[0] * sin(theta[1]) + coupler[1] * cos(theta[1]))
		- theta3dd * (coupler[0] * cos(theta[1]) - coupler[1] * sin(theta[1]));	// ycdd
}

SixBar::SixBar(double* r_arr, const double w, const double a) : Mechanisms(w, a)
{
	for (int i = 0; i < 8; i++)
		r[i] = r_arr[i];
}

void SixBar::Velocity(double* dst, double* theta)
{
	// theta = {theta2, theta3, theta4, theta6, theta7, theta8}
	dst[0] = r[1] * Omega() / r[2] * (sin(theta[0] - theta[2]) / sin(theta[2] - theta[1]));	// theta3d
	dst[1] = r[1] * Omega() / r[3] * (sin(theta[0] - theta[1]) / sin(theta[2] - theta[1]));	// theta4d
	dst[2] = r[5] * dst[1] / r[6] * (sin(theta[3] - theta[5]) / sin(theta[5] - theta[4]));	// theta7d
	dst[3] = r[5] * dst[1] / r[7] * (sin(theta[3] - theta[4]) / sin(theta[5] - theta[4]));	// theta8d
}

void SixBar::Acceleration(double* dst, double* theta, double* thetad)
{
	// theta = {theta2, theta3, theta4, theta6, theta7, theta8}
	// thetad = {theta3d, theta4d, theta7d, theta8d}
	dst[0] = (-r[1] * pow(Omega(), 2) * cos(theta[0] - theta[2]) - r[1] * Alpha() * sin(theta[0] - theta[2])
		- r[2] * pow(thetad[0], 2) * cos(theta[1] - theta[2])
		+ r[3] * pow(thetad[1], 2)) / (r[2] * sin(theta[1] - theta[2]));	// theta3dd
	dst[1] = (-r[1] * pow(Omega(), 2) * cos(theta[0] - theta[1]) - r[1] * Alpha() * sin(theta[0] - theta[1])
		- r[2] * pow(thetad[0], 2) + r[3] * pow(thetad[1], 2) * cos(theta[1] - theta[2]))
		/ (r[3] * sin(theta[1] - theta[2]));	// theta4dd
	dst[2] = (-r[5] * pow(thetad[1], 2) * cos(theta[3] - theta[5]) - r[5] * dst[1] * sin(theta[3] - theta[5])
		- r[6] * pow(thetad[2], 2) * cos(theta[4] - theta[5])
		+ r[7] * pow(thetad[3], 2)) / (r[6] * sin(theta[4] - theta[5]));	// theta7dd
	dst[3] = (-r[5] * pow(thetad[1], 2) * cos(theta[3] - theta[4]) - r[5] * dst[1] * sin(theta[3] - theta[4])
		- r[6] * pow(thetad[2], 2) + r[7] * pow(thetad[3], 2) * cos(theta[4] - theta[5]))
		/ (r[7] * sin(theta[4] - theta[5]));	// theta8dd
}