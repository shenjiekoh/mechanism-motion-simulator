#pragma once
#ifndef MECHANISM_H
#define MECHANISM_H

class Mechanisms
{
private:
	double omega;
	double alpha;

public:
	Mechanisms(const double omega = 0, const double alpha = 0);

	virtual void Velocity(double*, double*) = 0;
	virtual void Acceleration(double*, double*, double*) = 0;

	double Omega() { return omega; };
	double Alpha() { return alpha; };
};

class FourBar :public Mechanisms
{
private:
	double r[4];
	double coupler[2];
	bool fullRotation;

public:
	FourBar(double*, double*, const double, const double);
	
	virtual void Velocity(double*, double*);
	virtual void Acceleration(double*, double*, double*);

	double* getLength() { return r; };
	double* getCoupler() { return coupler; };
	bool getRotation() { return fullRotation; };
	void couplerPointVelocity(double*, double*, double*);
	void couplerPointAcceleration(double*, double*, double*, double*);
};

class SliderCrank :public Mechanisms
{
private:
	double r[3];
	double coupler[2];

public:
	SliderCrank(double*, double*, const double, const double);

	virtual void Velocity(double*, double*);
	virtual void Acceleration(double*, double*, double*);

	double* getLength() { return r; };
	double* getCoupler() { return coupler; };
	double stroke();
	double time_ratio();
	void couplerPointVelocity(double*, double*, double);
	void couplerPointAcceleration(double*, double*, double, double);
};

class SixBar :public Mechanisms
{
private:
	double r[8];

public:
	SixBar(double*, const double, const double);

	virtual void Velocity(double*, double*);
	virtual void Acceleration(double*, double*, double*);

	double* getLength() { return r; };
};
#endif