/*
 Project 6: Part 2 / 2
 Video: Chapter 3 Part 3

Create a branch named Part2

 References
 
 
 1) convert all of the pointer usage (except for 'const char*') to reference types or 
    const reference types **>>> WHERE POSSIBLE <<<**
        hint: There is no reference equivalent to nullptr.  
        if a pointer (including nullptr) is being returned anywhere, don't try to convert it to a reference.
 
 2) After you finish, click the [run] button.  Clear up any errors or warnings as best you can.
 
 */


#include <iostream>
#include <string>
struct T
{
    T(int v, const char* text) 
    : value(v), 
      name(text) 
    {

    }  //1

    int value; //2
    std::string name; //3
};

struct Comparison                                //4
{
    T* compare(T& a, T& b) //5
    {

        if( a.value < b.value ) return &a;
        if( a.value > b.value ) return &b;
        
        return nullptr;
    }
};

struct U
{
    float value1 { 0 }, value2 { 0 };
    float staticFunc(float& newVal)      //12
    {

        std::cout << "U's value1 value: " << this->value1 << std::endl;
        this->value1 = newVal;
        std::cout << "U's value1 updated value: " << this->value1 << std::endl;
        while( std::abs(this->value2 - this->value1) > 0.001f )
        {
            this->value2 += this->value1 / 2;
        } 
        
        std::cout << "U's staticVal2 updated value: " << this->value2 << std::endl;
        
        return this->value2 * this->value1;
    }
};

struct V
{
    static float staticFunc(U& that, float& newVal )        //10
    {
        std::cout << "U's value1 value: " << that.value1 << std::endl;
        that.value1 = newVal;
        std::cout << "U's value1 updated value: " << that.value1 << std::endl;
        while( std::abs(that.value2 - that.value1) > 0.001f )
        {
            /*
                write something that makes the distance between that-><#name2#> and that-><#name1#> get smaller
                */
            that.value2 += that.value1 / 2;
        }
        std::cout << "U's value2 updated value: " << that.value2 << std::endl;

        return that.value2 * that.value1;
    }
};
        
/*
 MAKE SURE YOU ARE NOT ON THE MASTER BRANCH

 Commit your changes by clicking on the Source Control panel on the left, entering a message, and click [Commit and push].
 
 If you didn't already: 
    Make a pull request after you make your first commit
    pin the pull request link and this repl.it link to our DM thread in a single message.

 send me a DM to review your pull request when the project is ready for review.

 Wait for my code review.
 */

int main()
{
    T t1(9, "text1");                                             //6
    T t2(3, "text2");                                             //6
    
    Comparison f;                                            //7
    auto* smaller = f.compare(t1, t2);                              //8
    if (smaller != nullptr)
    {
        std::cout << "the smaller one is << " << smaller->name << std::endl; //9
    }
    
    U anotherU;
    float updatedValue = 5.f;
    std::cout << "[static func] anotherU's multiplied values: " << V::staticFunc( anotherU, updatedValue) << std::endl;                  //11
    
    U yetAnotherU;
    std::cout << "[member func] yetAnotherU's multiplied values: " << yetAnotherU.staticFunc( updatedValue ) << std::endl;
}

        
        
        
        
        
        
        
