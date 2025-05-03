//anksilae@gmail.com

#include "SquareMat.hpp"
#include <iostream>
#include <cmath>

namespace matrix
{

    //--------------------------------//
    // Constructors and Destructor
    //--------------------------------//

    SquareMat::SquareMat(int size)
    : SquareMat(size, 0.0) // קריאה לבנאי עם סקלר
{}

    SquareMat::SquareMat(int size, double scalar) : size(size)
    {
        if (size < 1)
        {
            throw std::invalid_argument("Invalid matrix size.");
        }
        data = new double *[size];
        for (int i = 0; i < size; ++i)
        {
            data[i] = new double[size];
            for (int j = 0; j < size; ++j)
            {
                data[i][j] = scalar; // קובע את כל הערכים להיות הסקלר
            }
        }
    }

    SquareMat::SquareMat(const SquareMat &other) : size(other.size), data(new double *[other.size])
    {   
        for (int i = 0; i < size; ++i)
        {
            data[i] = new double[size]; // allocate new row
            for (int j = 0; j < size; ++j)
            {
                data[i][j] = other.data[i][j]; // copy value
            }
        }
    }

    SquareMat::~SquareMat()
    {
        for (int i = 0; i < size; ++i)
        {
            delete[] data[i];
        }
        delete[] data;
    }

    //--------------------------------//
    // Access operators
    //--------------------------------//

    double *SquareMat::operator[](int index)
    {
        if (index < 0 || index >= size)
        {
            throw std::invalid_argument("invalid index used");
        }
        return data[index];
    }

    const double *SquareMat::operator[](int index) const
    {
        if (index < 0 || index >= size)
            throw std::invalid_argument("invalid index used");
        return data[index];
    }

    //--------------------------------//
    // Assignment operators
    //--------------------------------//

    SquareMat &SquareMat::operator=(const SquareMat &other)
    {
        if (this != &other)
        {
            SquareMat temp(other);
            std::swap(size, temp.size);
            std::swap(data, temp.data);
        }
        return *this;
    }

    SquareMat &SquareMat::operator=(double scalar)
    {
        for (int i = 0; i < size; ++i)
        {
            for (int j = 0; j < size; ++j)
            {
                data[i][j] = scalar;
            }
        }
        return *this;
    }

    //--------------------------------//
    // Arithmetic operators
    //--------------------------------//

    SquareMat SquareMat::operator+(const SquareMat &other) const
    {
        if (size != other.size)
        {
            throw std::invalid_argument("sizes are different");
        }
        SquareMat ans = *this;
        for (int i = 0; i < size; ++i)
        {
            for (int j = 0; j < size; j++)
            {
                ans[i][j] += other[i][j];
            }
        }
        return ans;
}

    SquareMat SquareMat::operator-(const SquareMat &other) const
    {
        return (*this) + (-other);
    }

    SquareMat SquareMat::operator-() const
    {
        SquareMat ans = *this;
        for (int i = 0; i < size; ++i)
        {
            for (int j = 0; j < size; j++)
            {
                ans[i][j] = -ans[i][j];
            }
        }
        return ans;
    }

    SquareMat SquareMat::operator*(const SquareMat &other) const
    {
        if (size != other.size) throw std::invalid_argument("Matrix sizes do not match for multiplication");

        SquareMat ans(size, 0.0);

        for (int i = 0; i < size; ++i)
        {
            for (int j = 0; j < size; j++)
            {
                for (int k = 0; k < size; k++)
                {
                    ans[i][j] += data[i][k] * other[k][j];
                }
            }
        }
        return ans;
    }

    SquareMat operator*(const SquareMat &mat, double scalar)
    {
        SquareMat ans(mat.size, 0.0); // בונה מטריצה של אפסים בגודל מתאים

        for (int i = 0; i < mat.size; ++i)
        {
            for (int j = 0; j < mat.size; ++j)
            {
                ans[i][j] = mat[i][j] * scalar;
            }
        }
        return ans;
    }

    SquareMat operator*(double scalar, const SquareMat &mat)
    {
        return mat * scalar;
    }

    SquareMat SquareMat::operator%(const SquareMat &other) const
    {
        if (size != other.size) throw std::invalid_argument("Matrix sizes do not match for multiplication");
        SquareMat ans = *this;
        for (int i = 0; i < size; i++)
        {
            for (int j = 0; j < size; j++)
            {
                ans[i][j] *= other[i][j];
            }
        }
        return ans;
    }

    SquareMat SquareMat::operator%(int scalar) const
    {
        SquareMat ans = *this;
        for (int i = 0; i < size; i++)
        {
            for (int j = 0; j < size; j++)
            {
                ans[i][j] = std::fmod(ans[i][j], scalar);
            }
        }
        return ans;
    }

    SquareMat SquareMat::operator/(double scalar) const
    {
        if (std::abs(scalar) < 1e-9)
            throw std::invalid_argument("cannot be divided by zero (close to zero may cause overflow)!");
        SquareMat ans(size, 0.0); // בונה מטריצה של אפסים בגודל מתאים

        for (int i = 0; i < size; ++i)
        {
            for (int j = 0; j < size; ++j)
            {
                ans[i][j] = data[i][j] / scalar;
            }
        }
        return ans;
    }

    SquareMat SquareMat::operator^(int power) const
    {
        if (power < 0)
        {
            throw std::invalid_argument("cannot raise matrix to negative power!");
        }

        // נתחיל ממטריצת יחידה
        SquareMat ans(size, 0.0);
        for (int i = 0; i < size; ++i)
        {
            ans[i][i] = 1;
        }

        // נכפיל את ans בעצמנו power פעמים
        for (int i = 0; i < power; ++i)
        {
            ans = ans * (*this);
        }

        return ans;
    }

    SquareMat &SquareMat::operator++()
    {
        for (int i = 0; i < size; i++)
        {
            for (int j = 0; j < size; j++)
            {
                data[i][j]++;
            }
        }

        return *this;
    }

    SquareMat SquareMat::operator++(int)
    {
        SquareMat ans = *this;
        for (int i = 0; i < size; i++)
        {
            for (int j = 0; j < size; j++)
            {
                data[i][j]++;
            }
        }
        return ans;
    }

    SquareMat &SquareMat::operator--()
    {
        for (int i = 0; i < size; i++)
        {
            for (int j = 0; j < size; j++)
            {
                data[i][j]--;
            }
        }

        return *this;
    }

    SquareMat SquareMat::operator--(int)
    {
        SquareMat ans = *this;
        for (int i = 0; i < size; i++)
        {
            for (int j = 0; j < size; j++)
            {
                data[i][j]--;
            }
        }
        return ans;
    }

    SquareMat SquareMat::operator~() const
    {
        SquareMat ans(size, 0.0);
        for (int i = 0; i < size; i++)
        {
            for (int j = 0; j < size; j++)
            {
                ans[i][j] = data[j][i];
            }
        }
        return ans;
    }

    //--------------------------------//
    // Comparison operators
    //--------------------------------//

    bool SquareMat::operator==(const SquareMat &other) const
    {
        int compare = comparator(*this, other);
        return compare == 0;
    }

    bool SquareMat::operator!=(const SquareMat &other) const
    {
        int compare = comparator(*this, other);
        return compare != 0;
    }

    bool SquareMat::operator<(const SquareMat &other) const
    {
        int compare = comparator(*this, other);
        return compare == 1;
    }

    bool SquareMat::operator>(const SquareMat &other) const
    {
        int compare = comparator(*this, other);
        return compare == -1;
    }

    bool SquareMat::operator<=(const SquareMat &other) const
    {
        return *this < other || *this == other;
    }
    bool SquareMat::operator>=(const SquareMat &other) const
    {
        return *this > other || *this == other;
    }

    double SquareMat::operator!() const
    {
        int swapCount = 0;
        SquareMat upper = toUpperTriangular(swapCount);

        double det = 1.0;
        for (int i = 0; i < size; ++i)
        {
            det *= upper[i][i];
        }

        if (swapCount % 2 != 0)
        {
            det = -det;
        }

        return det;
    }

    //--------------------------//
    // Self application operators
    //--------------------------//

    SquareMat &SquareMat::operator+=(const SquareMat &other)
    {
        *this = *this + other;
        return *this;
    }

    SquareMat &SquareMat::operator-=(const SquareMat &other)
    {
        *this = *this - other;
        return *this;
    }

    SquareMat &SquareMat::operator*=(const SquareMat &other)
    {
        *this = (*this) * other;
        return *this;
    }

    SquareMat &SquareMat::operator/=(double scalar)
    {
        *this = (*this) / scalar;
        return *this;
    }

    SquareMat &SquareMat::operator%=(const SquareMat &other)
    {
        *this = (*this) % other;
        return *this;
    }

    SquareMat &SquareMat::operator*=(double scalar)
    {
        *this = (*this) * scalar;
        return *this;
    }

    SquareMat &SquareMat::operator%=(double scalar)
    {
        *this = (*this) % scalar;
        return *this;
    }

    //--------------------------//
    // Print
    //--------------------------//

    std::ostream &operator<<(std::ostream &out, const SquareMat &mat)
    {
        for (int i = 0; i < mat.size; ++i)
        {
            for (int j = 0; j < mat.size; ++j)
            {
                out << mat[i][j];
                if (j != mat.size - 1)
                {
                    out << " "; // רווח בין איברים
                }
            }
            out << "\n"; // ירידת שורה בסוף כל שורה
        }
        return out;
    }

    //--------------------------//
    // Private functions
    //--------------------------//

    SquareMat SquareMat::toUpperTriangular(int &swapCount) const
    {
        const double EPS = 1e-9;
        swapCount = 0;

        SquareMat result(*this); // התחלה מהעתק של המטריצה המקורית

        for (int i = 0; i < size; ++i)
        {
            // חיפוש הפיבוט
            int pivot = i;
            for (int j = i + 1; j < size; ++j)
            {
                if (std::fabs(result[j][i]) > std::fabs(result[pivot][i]))
                {
                    pivot = j;
                }
            }

            if (std::fabs(result[pivot][i]) < EPS)
            {
                // מטריצה סינגולרית => דטרמיננטה אפס
                break;
            }

            if (i != pivot)
            {
                std::swap(result.data[i], result.data[pivot]);
                swapCount++;
            }

            for (int j = i + 1; j < size; ++j)
            {
                double factor = result[j][i] / result[i][i];
                for (int k = i; k < size; ++k)
                {
                    result[j][k] -= factor * result[i][k];
                }
            }
        }

        return result;
    }
    double SquareMat::getSum() const
    {
        double sum = 0;
        for (int i = 0; i < size; i++)
        {
            for (int j = 0; j < size; j++)
            {
                sum += data[i][j];
            }
        }
        return sum;
    }
    int SquareMat::comparator(const SquareMat &a, const SquareMat &b) const
    {

        double aSum = a.getSum();
        double bSum = b.getSum();
        if (aSum > bSum)
            return -1;
        if (aSum < bSum)
            return 1;
        return 0;
    }

} // namespace matrix