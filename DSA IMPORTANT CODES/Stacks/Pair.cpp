//whenever we have to change private member sof the class by 
//accessing it from the outside, we have to use getters and setters

template<typename T> //we are specifying a temporary variable T
/*
If we want different variables to have different data types
template<typename T, typename V> 
and correspondingly change things int he class
*/
//what data type this T is will be revealed later on 

class Pair{
T x;
T y;

public:

void setX(T x)
{
    this->x=x;
}
T getX()
{
    return x;
}

void setY(T y)
{
    this->y=y;
}

T getY()
{
    return y;
}


};