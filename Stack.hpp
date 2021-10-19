#ifndef STACK_HPP
#define STACK_HPP

#include "./Vector.hpp"

namespace ft 
{
    template <class T, class Container =  vector<T> >
    class stack
    {
        public:
        // ANCHOR - This is member types
        typedef T           value_type;
        typedef Container   container_type;
        typedef size_t      size_type;

        //TODO - Construct stack
        explicit stack(const container_type& ctnr = container_type()) : c(ctnr)
        {
        }
        //TODO - Test whether container is empty
        bool empty() const
        {
            return (c.empty());
        }
        private:
            container_type c;
    };
}

#endif