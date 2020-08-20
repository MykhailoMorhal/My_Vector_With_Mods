#ifndef CPP_VECTOR_HPP_
#define CPP_VECTOR_HPP_

/*----------------------------------------------------------------------
                                Include
*----------------------------------------------------------------------*/
#include <cassert>
#include <iostream>
#include <exception>
#include <string.h>

/**
 * @brief Vector. Holds pointers to the beginning. Items are located in dynamically allocated array.
 * The array is extended if required. The size of the array doubled each time.
 * @param T Type of items.
 */
template<typename T>
class CVector
{

public:

    /**
     * @brief Iterator for vector container. It is a random access iterator.
     * @tparam T Type of items.
     */
    class CVectorIterator
    {
        /**
         * @brief Pointer to data.
         */
        T* mPtr;
    public:

        /*----------------------------------------------------------------------
                                Constructors & Destructors
        *----------------------------------------------------------------------*/
        CVectorIterator(T* const aPtr)
            : mPtr(aPtr)
        {}

        CVectorIterator() = delete;

        CVectorIterator(const CVectorIterator&) = default;

        CVectorIterator(CVectorIterator&&) = default;

        ~CVectorIterator()
        {
            if(mPtr)
            {
                delete mPtr;
            }
        }

        /*----------------------------------------------------------------------
                                Overload operators
        *----------------------------------------------------------------------*/

        /**
         * @brief Operator add
         */
        CVectorIterator operator+(const int aDiffIndex) const
        {
            CVectorIterator tmp = mPtr + aDiffIndex;
            return tmp;
        }

        /**
         * @brief Operator sub
         */
        CVectorIterator operator-(const int aDiffIndex) const
        {
            CVectorIterator tmp = mPtr - aDiffIndex;
            return tmp;
        }

        /**
         * @brief Opereator increment ++
         */
        CVectorIterator& operator++()
        {
            mPtr++;
            return *this;
        }
        /**
         * @brief Opereator ++ increment
         */
        CVectorIterator operator++(int)
        {
            CVectorIterator tmp = mPtr;
            ++tmp; // pre-increment
            return tmp;
        }

        /**
         * @brief Opereator decrement --.
         */
        CVectorIterator& operator--()
        {
            mPtr--;
            return *this;
        }

        /**
         * @brief Opereator -- decrement.
         */
        CVectorIterator operator--(int)
        {
            CVectorIterator tmp = mPtr; // copy
            --tmp; // pre-increment
            return tmp;
        }

        /**
         * @brief Opereator *
         */
        const T& operator *() const
        {
            return *mPtr;
        }

        /**
         * @brief Opereator ->
         */
        const T* operator ->() const
        {
            return mPtr;
        }

        /**
         * @brief Opereator - 
         */
        int operator -(const CVectorIterator& alt)
        {
            return mPtr - alt.mPtr;
        }

        /**
         * @brief Opereator ==
         */
        bool operator ==(const CVectorIterator& alt)
        {
            return (mPtr == alt.mPtr);
        }

        /**
         * @brief Opereator !=
         */
        bool operator !=(const CVectorIterator& alt)
        {
            return !(*this == alt);
        }

        /**
         * @brief Opereator <
         */
        bool operator <(const CVectorIterator& alt)
        {
            return (mPtr < alt.mPtr);
        }

        /**
         * @brief Opereator <= 
         */
        bool operator <=(const CVectorIterator& alt)
        {
            return ((*this < alt) || (*this == alt));
        }

        /**
         * @brief Opereator > 
         */
        bool operator >(const CVectorIterator& alt)
        {
            return !(*this <= alt);
        }

        /**
         * @brief Opereator >=
         */
        bool operator >=(const CVectorIterator& alt)
        {
            return ((*this > alt) || (*this == alt));
        }

        ///@TODO

    };

    // /////////////////////////////////////////////////////////////////////
    // /////////////////////////////////////////////////////////////////////
    // /////////////////////////////////////////////////////////////////////

    /**
     * @brief Reverse iterator for vector container. It is a random access iterator.
     * @tparam T Type of items.
     */
    class CReverseVectorIterator
    {
        /**
         * @brief Pointer to data.
         */
        T* mPtr;
    public:
        
        /*----------------------------------------------------------------------
                                Constructors & Destructors
        *----------------------------------------------------------------------*/
        CReverseVectorIterator(T* aPtr)
            : mPtr(aPtr)
        {}

        CReverseVectorIterator() = delete;

        CReverseVectorIterator(const CReverseVectorIterator&) = default;

        CReverseVectorIterator(CReverseVectorIterator&&) = default;

        ~CReverseVectorIterator()
        {
            if (mPtr)
            {
                delete mPtr;
            }
        }

        /*----------------------------------------------------------------------
                                Overload operators
        *----------------------------------------------------------------------*/
        /**
         * @brief Operator add
         */
        CReverseVectorIterator operator+(const int aDiffIndex) const
        {
            CReverseVectorIterator tmp = mPtr - aDiffIndex;
            return tmp;
        }

        /**
         * @brief Operator sub
         */
        CReverseVectorIterator operator-(const int aDiffIndex) const
        {
            CReverseVectorIterator tmp = mPtr + aDiffIndex;
            return tmp;
        }

        /**
         * @brief Opereator increment ++
         */
        CReverseVectorIterator& operator++()
        {
            mPtr--;
            return *this;
        }

        /**
         * @brief Opereator ++ increment
         */
        CReverseVectorIterator operator++(int)
        {
            CReverseVectorIterator tmp = mPtr; // copy
            --tmp; // pre-increment
            return tmp;
        }

        /**
         * @brief Opereator decrement --
         */
        CReverseVectorIterator& operator--()
        {
            mPtr++;
            return *this;
        }

        /**
         * @brief Opereator -- decrement
         */
        CReverseVectorIterator operator --(int)
        {
            CReverseVectorIterator tmp = mPtr; // copy
            ++tmp; // pre-increment
            return tmp;
        }

        /**
         * @brief Opereator *
         */
        const T& operator *() const
        {
            return *mPtr;
        }

        /**
         * @brief Opereator ->
         */
        const T* operator ->() const
        {
            return mPtr;
        }

        /**
         * @brief Opereator - when you want sub another VectorIterator
         */
        int operator -(const CReverseVectorIterator& alt)
        {
            return alt.mPtr - mPtr;
        }

        /**
         * @brief Opereator ==
         */
        bool operator ==(const CReverseVectorIterator& alt)
        {
            return mPtr == alt.mPtr;
        }

        /**
         * @brief Opereator != 
         */
        bool operator !=(const CReverseVectorIterator& alt)
        {
            return !(*this == alt);
        }

        /**
         * @brief Opereator < compared this Iterator with another Iterator
         */
        bool operator <(const CReverseVectorIterator& alt)
        {
            return (mPtr > alt.mPtr);
        }

        /**
         * @brief Opereator <= 
         */
        bool operator <=(const CReverseVectorIterator& alt)
        {
            return ((*this < alt) || (*this == alt));
        }

        /**
         * @brief Opereator > 
         */
        bool operator >(const CReverseVectorIterator& alt)
        {
            return !(*this <= alt);
        }

        /**
         * @brief Opereator >= 
         */
        bool operator >=(const CReverseVectorIterator& alt)
        {
            return ((*this > alt) || (*this == alt));
        }

    };

    // /////////////////////////////////////////////////////////////////////
    // /////////////////////////////////////////////////////////////////////
    // /////////////////////////////////////////////////////////////////////

    using DIterator = CVectorIterator;
    using DReverseIterator = CReverseVectorIterator;

    /*----------------------------------------------------------------------
                         Constructors & Destructors
    *----------------------------------------------------------------------*/
    CVector()
        : mCapacity(defaultCapacitySize::CAPACITY_SIZE)
        , mBegin(new T[defaultCapacitySize::CAPACITY_SIZE])
        , mSize(NULL)
    {}

    CVector(const CVector& aObj)
    {
        if (!aObj.empty())
        {
            mCapacity = aObj.mCapacity;
            mBegin = new T[mCapacity];
            mSize = aObj.mSize;

            memcpy(mBegin, aObj.mBegin, sizeof(T) * aObj.mSize);
        }
        else
        {
            mBegin(new T[defaultCapacitySize::CAPACITY_SIZE]);
        }
    }
	
	/**
	 * @brief Destructor. Deallocates memory.
	 */
	~CVector()
	{
		delete[] mBegin;
		mBegin = nullptr;
	}

    /*----------------------------------------------------------------------
                                Overload operators
    *----------------------------------------------------------------------*/
    CVector& operator=(const CVector& aObj)
    {
        if (!aObj.empty())
        {
            if (this != &aObj)
            {
                clearCVector();
                mCapacity = aObj.mCapacity;
                mBegin = new T[mCapacity];
                mSize = aObj.mSize;

                memcpy(mBegin, aObj.mBegin, (sizeof(T) * aObj.mSize));
            }
        }
        else
        {
            clearCVector();
            mBegin(new T[defaultCapacitySize::CAPACITY_SIZE]);
        }
        return *this;
    }

    /**
     * @brief Compares vectors
     */
    bool operator==(const CVector& aObj)
    {
        if (mBegin == aObj.mBegin)
        {
            return true;
        }

        if (mSize != aObj.mSize)
        {
            return false;
        }

        return (0 == memcmp(mBegin, aObj.mBegin, (sizeof(T) * aObj.mSize)));
    }

    /**
     * @brief Compares vectors
     */
    bool operator!=(const CVector& aObj)
    {
        return !(*this == aObj);
    }
	
	/*----------------------------------------------------------------------
                                Methods
	 *----------------------------------------------------------------------*/

    /**
     * @brief Returns the number of objects.
     * Complexity: O(1) - because vector has size field.
     * @return Number of objects.
     */
    unsigned int size() const
    {
        return mSize;
    }

    /**
     * @brief Adds an item at the end of the array.
     * Complexity: O(n) - because in the worst case, when new array will be allocated, it has to copy all elements
     * to new array. In most cases complexity will be O(1).
     * @param aValue Item that will be added.
     */
    void pushBack(const T& aValue)
    {
        if (empty())
        {
            mBegin[0] = aValue;
            mSize++;
        }
        else
        {
            mSize++;
            if ((mSize) == (mCapacity))
            {
                increaseCVector();
            }
            mBegin[mSize - 1] = aValue;
        }
    }

    /**
     * @brief Pops the last item from the array. It doesn't deallocate memory, so destructor of the object in array
     * is not called.
     * Complexity: O(1) - because access to any element of the array is constant.
     * @return THe last item from the array.
     */
    T popBack()
    {
        if (empty())
        {
            throw std::exception("Try to delete from empty vector");
        }

        mSize--;
        return mBegin[mSize];
    }

    /**
     * @brief Pushes item to the front of the array.
     * Complexity: O(n) - All item have to be copied.
     * @param aValue Item that will be added.
     */
    void pushFront(const T& aValue)
    {
        insert(0, aValue);
    }

    /**
     * @brief Pops the first item from the array. There wouldn't be called destructor of object from array. All items
     * except the first one will be copied to new location: the second object would be copied to the first item.
     * Complexity: O(n) - All items have to copied.
     * @return The first item from the array.
     */
    T popFront()
    {
        if (!empty())
        {
			mSize--;
            if (mSize == 1)
            {
                return mBegin[mSize];
            }
            else
            {
                T arg = mBegin[0];
				T* newmBegin = new T[mCapacity];
				memcpy( newmBegin, mBegin + sizeof(T), (sizeof(T) * mSize));
				delete[] mBegin;
				mBegin = newmBegin;
				newmBegin = nullptr;
				return arg;
            }
        }
        throw std::exception("Try to delete from empty vector");
    }

    /**
     * @brief Checks if the vector contains given object.
     * Complexity: O(n) - The worst case: the vector doesn't contain the given item, or it is on the last position.
     * In both cases entire array have to be checked.
     * @param aValue Item to find.
     * @return True if the vector contains the given item; otherwise false.
     */
    bool contains(const T& aValue)
    {
        if (!empty())
        {
            for (uintmax_t i = 0; i < mSize; i++)
            {
                if (mBegin[i] == aValue)
                {
                    return true;
                }
            }
			
        }
        return false;
    }

    /**
     * @brief Indicates if the vector is empty.
     * Complexity: O(1) - because the vector contains size field.
     * @return True if vector is empty; otherwise false.
     */
    bool empty() const
    {
        return ( 0 == mSize);
    }

    /**
     * @brief Returns pointer to the item at the given position.
     * Complexity: O(1) - because access to any element of the array is constant.
     * @param aIndex Index of item in the array.
     * @return Pointer to the item at the given position or null if the index is greater than the size of vector.
     */
    const T* get(unsigned int aIndex) const
    {
        if (aIndex >= mSize)
        {
            return nullptr;
        }
        else
        {
            return &mBegin[aIndex];
        }
    }

    /**
     * @brief Inserts the given item on the given position. Items at the given position and after it are copied.
     * Complexity: O(n) - because in the worst case, when aIndex is zero, all items in the array have to be copied to
     * their new position.
     * @param aIndex Position when the given item should be put.
     * @param aValue Item to insert.
     */
    void insert(unsigned int aIndex, const T& aValue)
    {
        if ((0 == aIndex) && empty() )
        {
            mBegin[0] = aValue;
            mSize++;
        }
        else if (aIndex < mSize)
        {
            if (aIndex == (mSize - 1))
            {
                T arg = mBegin[aIndex];
                mBegin[aIndex] = aValue;
                mSize++;
                if (mSize == mCapacity)
                {
                    increaseCVector();
                }
                mBegin[aIndex + 1] = arg;
            }
            else
            {
                mSize++;
                if (mSize == mCapacity)
                {
                    increaseCVector();
                }

                for (uintmax_t i = mSize - 1; i > aIndex; i--)
                {
                    mBegin[i] = mBegin[i - 1];
                }

                mBegin[aIndex] = aValue;
            }
        }
        else
        {
            throw std::exception("Try insert to wrong element");
        }
    }

    /**
     * @brief Returns a random access iterator that points to the beginning.
     * @return Iterator to the beginning.
     */
    DIterator begin()
    {
        return DIterator(mBegin);
    }

    /**
     * @brief Returns a random access iterator that points to the item after the last one.
     * @return Iterator to the item after the last one.
     */
    DIterator end()
    {
        return DIterator(&mBegin[mSize]);
    }

    /**
     * @brief Returns a reverse random access iterator that points to the last item.
     * @return Reverse iterator to the last item.
     */
    DReverseIterator rbegin()
    {
        return DReverseIterator(&mBegin[mSize - 1]);
    }

    /**
     * @brief Returns a reverse random access iterator that points to the item before the first one.
     * @return Reverse iterator to the item before the first one.
     */
    DReverseIterator rend()
    {
        return DReverseIterator(mBegin - 1);
    }

    /**
     * @brief return pointer to the dynamically allocated array to which item will be put
     * @return mBegin.
     */
    T* data()
    {
        return mBegin;
    }

private:

    /**
     * @brief Clear Vector.
     */

    void clearCVector()
    {
        delete[] mBegin;
        mBegin = nullptr;
        mCapacity = defaultCapacitySize::CAPACITY_SIZE;
        mSize = NULL;
    }

    /**
     * @brief Increase CVector when mSize == mCapacity.
     */

    void increaseCVector()
    {
        mCapacity += defaultCapacitySize::CAPACITY_SIZE;
        T* newmBegin = new T[mCapacity];
        memcpy(newmBegin, mBegin, (sizeof(T) * mSize));
        delete[] mBegin;
        mBegin = newmBegin;
        newmBegin = nullptr;
    }

    /**
     * @brief Pointer to the dynamically allocated array to which item will be put.
     */
    T* mBegin;

    /**
     * @brief Number of elements in the array.
     */
    unsigned int mSize;

    /**
     * @brief Size of allocated memory. Only if vector is full it is the same as mSize.
     */
    unsigned int mCapacity;

    /**
     * @brief Enum for deafault initialization
     */
    enum defaultCapacitySize { CAPACITY_SIZE = 16 };
};

#endif
