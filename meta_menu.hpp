/////////////////////////////////////////////////////////////////////////////////////////
#ifndef META_MENU_HPP
#define META_MENU_HPP
/////////////////////////////////////////////////////////////////////////////////////////
#include <functional>
#include <list>
/////////////////////////////////////////////////////////////////////////////////////////
namespace tools
{
/////////////////////////////////////////////////////////////////////////////////////////
    template<typename T, typename Cont = std::list<T>>
    class Meta_menu
    {
        //-------------------------------------------------------------------------------
    public:
        //-------------------------------------------------------------------------------
        using iterator = typename Cont::iterator;
        using const_iterator = typename Cont::const_iterator;
        using reverse_iterator = typename Cont::reverse_iterator;
        using const_reverse_iterator = typename Cont::const_reverse_iterator;
        using result_type = typename T::result_type;
        //-------------------------------------------------------------------------------
        iterator insert( const_iterator pos, T& value )
        {
            return functions.insert( pos, value );
        }
        //-------------------------------------------------------------------------------
        iterator insert( const int pos, const T& value )
        {
            auto iter = functions.begin();
            std::advance( iter, pos - 1 );
            return functions.insert( iter, value );
        }
        //-------------------------------------------------------------------------------
        iterator insert( const_iterator pos, std::initializer_list<T> i_list )
        {
            return functions.insert( pos, i_list );
        }
        //-------------------------------------------------------------------------------
        iterator insert( const int pos, std::initializer_list<T> i_list )
        {
            auto iter = functions.begin();
            std::advance( iter, pos - 1 );
            return insert( iter, i_list );
        }
        //-------------------------------------------------------------------------------
        void push_back( const T& value )
        {
            functions.push_back( value );
        }
        //-------------------------------------------------------------------------------
        void push_back( T&& value )
        {
            functions.push_back( std::forward<T>(value) );
        }
        //-------------------------------------------------------------------------------
        void push_front( const T& value )
        {
            functions.push_front( value );
        }
        //-------------------------------------------------------------------------------
        void push_front( T&& value )
        {
            functions.push_front( std::forward<T>(value) );
        }
        //-------------------------------------------------------------------------------
        template<typename... Args>
        result_type call( iterator pos, Args&&... args )
        {
            return (*pos)( std::forward<Args>(args...)... );
        }
        //-------------------------------------------------------------------------------
        template<typename... Args>
        result_type call( const int pos, Args&&... args )
        {
            auto iter = functions.begin();
            std::advance( iter, pos - 1 );
            return call( iter, std::forward<Args>(args...)... );
        }
        //-------------------------------------------------------------------------------
        iterator erase( const_iterator pos )
        {
            return functions.erase( pos );
        }
        //-------------------------------------------------------------------------------
        iterator erase( const int pos )
        {
            auto iter = functions.begin();
            std::advance( iter, pos - 1 );
            return erase( iter );
        }
        //-------------------------------------------------------------------------------
        iterator erase( const_iterator from, const_iterator to )
        {
            return functions.erase( from, to );
        }
        //-------------------------------------------------------------------------------
        size_t size() const noexcept
        {
            return functions.size();
        }
        //-------------------------------------------------------------------------------
        iterator begin() noexcept
        {
            return functions.begin();
        }
        //-------------------------------------------------------------------------------
        iterator end() noexcept
        {
            return functions.end();
        }
        //-------------------------------------------------------------------------------
        const_iterator cbegin() noexcept
        {
            return functions.cbegin();
        }
        //-------------------------------------------------------------------------------
        const_iterator cend() noexcept
        {
            return functions.cend();
        }
        //-------------------------------------------------------------------------------
        reverse_iterator rbegin() noexcept
        {
            return functions.rbegin();
        }
        //-------------------------------------------------------------------------------
        reverse_iterator rend() noexcept
        {
            return functions.rend();
        }
        //-------------------------------------------------------------------------------
        const_reverse_iterator crbegin() noexcept
        {
            return functions.crbegin();
        }
        //-------------------------------------------------------------------------------
        const_reverse_iterator crend() noexcept
        {
            return functions.crend();
        }
        //-------------------------------------------------------------------------------
    private:
        //-------------------------------------------------------------------------------
        Cont functions;
        //-------------------------------------------------------------------------------
    };
/////////////////////////////////////////////////////////////////////////////////////////
} //tools
/////////////////////////////////////////////////////////////////////////////////////////
#endif //META_MENU_HPP
/////////////////////////////////////////////////////////////////////////////////////////