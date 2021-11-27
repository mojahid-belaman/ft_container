#ifndef STACK_HPP
#define STACK_HPP

#include "./Vector.hpp"

namespace ft 
{
    template <class T, class Container =  ft::vector<T> >
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
            return (this->c.empty());
        }
        //TODO - Return size
        size_type size() const
        {
            return (this->c.size());
        }
        //TODO - Access next element
        value_type& top()
        {
            return (this->c.back());
        }
        const value_type& top() const
        {
            return (this->c.back());
        }
        //TODO - Insert element
        void push (const value_type& val)
        {
            this->c.push_back(val);
        }
        //TODO - Remove top element
        void pop()
        {
            this->c.pop_back();
        }
        //TODO - Relational operators for stack
        template <class t, class c>
        friend bool operator== (const stack<t, c>& lhs, const stack<t, c>& rhs);
        template <class t, class c>
        friend bool operator!= (const stack<t, c>& lhs, const stack<t, c>& rhs);
        template <class t, class c>
        friend bool operator< (const stack<t, c>& lhs, const stack<t, c>& rhs);
        template <class t, class c>
        friend bool operator<= (const stack<t, c>& lhs, const stack<t, c>& rhs);
        template <class t, class c>
        friend bool operator> (const stack<t, c>& lhs, const stack<t, c>& rhs);
        template <class t, class c>
        friend bool operator>= (const stack<t, c>& lhs, const stack<t, c>& rhs);
        
        protected:
            container_type c;
    };

    template <class T, class Container>
    bool operator== (const stack<T,Container>& lhs, const stack<T,Container>& rhs)
    {
        return (lhs.c == rhs.c);
    }
    template <class T, class Container>
    bool operator!= (const stack<T,Container>& lhs, const stack<T,Container>& rhs)
    {
        return (lhs.c != rhs.c);
    }
    template <class T, class Container>
    bool operator< (const stack<T,Container>& lhs, const stack<T,Container>& rhs)
    {
        return (lhs.c < rhs.c);
    }
    template <class T, class Container>
    bool operator<= (const stack<T,Container>& lhs, const stack<T,Container>& rhs)
    {
        return (lhs.c <= rhs.c);
    }
    template <class T, class Container>
    bool operator> (const stack<T,Container>& lhs, const stack<T,Container>& rhs)
    {
        return (lhs.c > rhs.c);
    }
    template <class T, class Container>
    bool operator>= (const stack<T,Container>& lhs, const stack<T,Container>& rhs)
    {
        return (lhs.c >= rhs.c);
    }
}

#endif