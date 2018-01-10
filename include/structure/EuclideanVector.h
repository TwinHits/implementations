#ifndef EUCLIDEANVECTOR_H
#define EUCLIDEANVECTOR_H

#define _USE_MATH_DEFINES
#include <cmath>

template <typename T>
class EuclideanVector
{
	public:
		EuclideanVector(T x2, T y2); EuclideanVector(T x1, T y1, T x2, T y2);
		
		T getX();
		T getY();

		T getDirection();
		T getMagnitude();

		void normalize();
		void limit();
		
		EuclideanVector<T> operator+=(EuclideanVector<T>& rhs);
		EuclideanVector<T> operator+(EuclideanVector<T>& rhs);
		EuclideanVector<T> operator-(EuclideanVector<T>& rhs);
	private:
		T x;
		T y;

		T magnitude;
		T direction;
};

template <typename T>
EuclideanVector<T>::EuclideanVector(T x2, T y2) : EuclideanVector<T>::EuclideanVector(0, 0, x2, y2)
{

}

template <typename T>
EuclideanVector<T>::EuclideanVector(T x1, T y1, T x2, T y2)
{
	//Conversion from cartesian to polar
	this->x = x2 - x1;
	this->y = y2 - y1;	

	this->magnitude = std::hypot(x, y);
	
	this->direction = std::atan(y/x);
	this->direction = (this->direction*180)/M_PI;

	if (y >= 0 && x >= 0)
		direction = direction;	
	else if	(x < 0 && y < 0)
		direction = direction;
	else
		direction = direction + 180;
}

template <typename T>
T EuclideanVector<T>::getX() 
{ 
	return this->x; 
}

template <typename T>
T EuclideanVector<T>::getY()
{ 
	return this->y;
}

template <typename T>
T EuclideanVector<T>::getDirection() 
{ 
	return this->direction; 
}

template <typename T>
T EuclideanVector<T>::getMagnitude()
{ 
	return this->magnitude;
}

template <typename T>
void EuclideanVector<T>::normalize()
{
	if (magnitude != 0)
	{
		this->x = x/magnitude;
		this->y = y/magnitude;
	}
}

template <typename T>
EuclideanVector<T> EuclideanVector<T>::operator+=(EuclideanVector<T>& rhs)
{
	return EuclideanVector<T>(this->x + rhs.x, this->y + rhs.y);
}

template <typename T>
EuclideanVector<T> EuclideanVector<T>::operator+(EuclideanVector<T>& rhs)
{
	return *this += rhs;
}

template <typename T>
EuclideanVector<T> EuclideanVector<T>::operator-(EuclideanVector<T>& rhs)
{
	return EuclideanVector<T>(this->x + -rhs.x, this->y + -rhs.y);
}

#endif
