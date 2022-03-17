/*
Currently only used for vector 2
TODO: Understand more about the math here
*/
#pragma once
#include <math.h>
//Defines PI, and converting degrees to radians
#define PI 3.14159265
#define DEG_TO_RAD PI / 180.0f
#define RAD_TO_DEG 180.0f / PI

namespace oni
{
    //Vector2 struct
    struct Vector2
    {   
        //X and Y variables
        float x;
        float y;
        //Constructor
        Vector2(float _x = 0.0f, float _y = 0.0f)
        :x(_x), y(_y) {}
        //Various math functions
        float MagnitudeSqr()
        {
            return x*x + y*y;
        }

        float Magnitude()
        {
            return (float)sqrt(x*x + y*y);
        }

        Vector2 Normalized()
        {
            float mag = Magnitude();

            return Vector2(x/mag, y/mag);
        }
        //Defines operators
        Vector2& operator +=(const Vector2& rhs)
        {
            x += rhs.x;
            y += rhs.y;

            return *this;
        }

        Vector2& operator -=(const Vector2& rhs)
        {
            x -= rhs.x;
            y -= rhs.y;

            return *this;
        }

        Vector2& operator *=(const Vector2& rhs)
        {
            x *= rhs.x;
            y *= rhs.y;

            return *this;
        }


        Vector2 operator -() const 
        {
            return Vector2(-x, -y);
        }
    };
    //Other operators
    inline Vector2 operator +(const Vector2& lhs, const Vector2& rhs)
    {
        return Vector2(lhs.x + rhs.x, lhs.y + rhs.y);
    }

    inline Vector2 operator -(const Vector2& lhs, const Vector2& rhs)
    {
        return Vector2(lhs.x - rhs.x, lhs.y - rhs.y);
    }

    inline Vector2 operator *(const Vector2& lhs, const float& rhs)
    {
        return Vector2(lhs.x * rhs, lhs.y * rhs);
    }

    inline Vector2 operator /(const Vector2& lhs, const float& rhs)
    {
        return Vector2(lhs.x / rhs, lhs.y / rhs);
    }

    inline Vector2 operator *(const Vector2& lhs, const Vector2& rhs)
    {
        return Vector2(lhs.x * rhs.x, lhs.y * rhs.y);
    }

    inline Vector2 operator /(const Vector2& lhs, const Vector2& rhs)
    {
        return Vector2(lhs.x / rhs.x, lhs.y / rhs.y);
    }

    /**
    * @brief Return a vector rotated by an angle
    * @param vec Vector to rotate
    * @param angle Amount to rotate the vector by
    */
    inline Vector2 RotateVector(Vector2 vec, float angle)
    {
        float radAngle = (float)(angle*DEG_TO_RAD);

        return Vector2((float)(vec.x * cos(radAngle) - vec.y * sin(radAngle)), (float)(vec.x * sin(radAngle) + vec.y * cos(radAngle)));
    }

    /**
    * @brief Return the dot product between two vectors
    * @param vec1 First vector 
    * @param vec2 Second vector
    */
    inline float Dot(const Vector2& vec1, const Vector2& vec2)
    {
        return vec1.x * vec2.x + vec1.y * vec2.y;
    }

    /**
     * @brief Return a float clamped between the given min and max 
     * @param value Value being clamped
     * @param min Minimum value to clamp to
     * @param max Maximum value to clamp to
     */    
    inline float Clamp(const float& value, const float& min, const float& max)
    {
        if(value > max)
            return max;
        if(value < min)
            return min;
        return value;
    }

    /**
     * @brief Return the distance between two vectors
     * @param vec1 First vector
     * @param vec2 Second vector
    */
    inline Vector2 Distance(Vector2 vec1, Vector2 vec2)
    {
        return Vector2(vec1.x - vec2.x, vec1.y - vec2.y);
    }

    /**
     * @brief Return the linear interpolation between two values
     * @param start Initial value
     * @param end Desired value
     * @param interpolation Amount to interpolate by 
    */
    inline float Lerp(float start, float end, float interpolation)
    {
        return start + (start - end) * interpolation;
    }

    /**
     * @brief Return the linear interpolation between two Vector2s
     * @param vec1 First vector2
     * @param vec2 Second Vector2
     * @param interpolation Amount to interpolate by 
    */
    inline Vector2 VectorLerp(Vector2 vec1, Vector2 vec2, float interpolation)
    {
        return Vector2(Lerp(vec1.x, vec2.x, interpolation), Lerp(vec1.x, vec2.x, interpolation));
    }

    const Vector2 VEC2_ZERO = {0.0f, 0.0f};
    const Vector2 VEC2_ONE = {1.0f, 1.0f};
    const Vector2 VEC2_UP = {0.0f, -1.0f};
    const Vector2 VEC2_DOWN = {0.0f, 1.0f};
    const Vector2 VEC2_RIGHT = {1.0f, 0.0f};
    const Vector2 VEC2_LEFT = {-1.0f, 0.0f};
}