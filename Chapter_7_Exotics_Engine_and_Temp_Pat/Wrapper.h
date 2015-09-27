
// Note: It is actually an self-defined smart pointer which will do the deep copy (copy the pointed object as well)

#ifndef WRAPPER_H
#define WRAPPER_H

template< class T>
class Wrapper
{
public:

    // This default constructor enables to have a Wrapper object which points to nothing.
    // Enable std::vector<Wrapper<MCStatistics> > StatisticsGatherers(10); to compile in that it
    // calls the default constructor of the wrapper object. 
    Wrapper() { DataPtr =0;}
	
    Wrapper(const T& inner)
    {
        DataPtr = inner.clone();
    }

    ~Wrapper()
    {
        if (DataPtr !=0)
            delete DataPtr;
    }

    Wrapper(const Wrapper<T>& original)
    {
        if (original.DataPtr !=0)
            DataPtr = original.DataPtr->clone();
        else
            DataPtr=0;
    }

    Wrapper& operator=(const Wrapper<T>& original)
	{
            if (this != &original)
            {
                if (DataPtr!=0)
                    delete DataPtr;

                DataPtr = (original.DataPtr !=0) ? original.DataPtr->clone() : 0;
            }
            return *this;
	}

    T& operator*()
    {
        return *DataPtr;
    }

    const T& operator*() const
    {
        return *DataPtr;
    }
	
    // This function enables to use myWrapper->theMethod() rather 
    // than (*mywrapper).theMethod(), where theMethod is one of the methods of the member object.
    // Const version.
    const T* const operator->() const
    {
        return DataPtr;
    }

    // This function enables to use myWrapper->theMethod() rather 
    // than (*mywrapper).theMethod(), where theMethod is one of the methods of the member object.
    // Non-const version.
    T* operator->()
    {
        return DataPtr;
    }

private:
    T* DataPtr;
};

#endif
