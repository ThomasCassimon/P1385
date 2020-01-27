/*
 * @author thomas
 * @date 1/27/20.
 */

#pragma once

#include <linear_algebra.hpp>

namespace std::math
{
	template <class T, class AT>
	class dr_vector_engine
	{
		public:
			//-	Types
			//
			using engine_category		= resizable_vector_engine_tag;
			using element_type			= T;
			using value_type			= remove_cv_t<T>;
			using allocator_type		= AT;
			using pointer				= typename allocator_traits<AT>::pointer;
			using const_pointer			= typename allocator_traits<AT>::const_pointer;
			using reference				= element_type&;
			using const_reference		= const element_type&;
			using difference_type		= ptrdiff_t;
			using size_type				= size_t;
			// todo: These 2 are implementation defined, check if there's a better type for this
			using iterator				= pointer;
			using const_iterator		= const_pointer;

			//-	Construct/copy/destroy
			//
			~dr_vector_engine();

			dr_vector_engine();
			dr_vector_engine(dr_vector_engine&&) noexcept;
			dr_vector_engine(const dr_vector_engine&);

			template <class U>
			dr_vector_engine(initializer_list<U> list);
			dr_vector_engine(size_type elems);
			dr_vector_engine(size_type elems, size_type elem_cap);

			dr_vector_engine&	operator=	(dr_vector_engine&& rhs) noexcept;
			dr_vector_engine&	operator=	(const dr_vector_engine& rhs);

			template <class ET2>
			dr_vector_engine&	operator=	(const ET2&	rhs);

			//-	Iterators
			//
			iterator 		begin()				noexcept;
			iterator		end()				noexcept;
			const_iterator	begin() 	const	noexcept;
			const_iterator	end()		const	noexcept;
			const_iterator 	cbegin()	const	noexcept;
			const_iterator	cend()		const	noexcept;

			//-	Capacity
			//
			size_type	capacity()	const noexcept;
			size_type	elements()	const noexcept;

			void reserve(size_type cap);
			void resize(size_type elems);
			void resize(size_type elems, size_type cap);

			//-	Element access
			reference		operator()	(size_type i);
			const_reference	operator()	(size_type i) const;

			//- Modifiers
			//
			void swap(dr_vector_engine& rhs)				noexcept;
			void swap_elements(size_type i, size_type j)	noexcept;

		private:

	};

	template<class T, class AT>
	dr_vector_engine<T, AT>::~dr_vector_engine()
	{

	}

	template<class T, class AT>
	dr_vector_engine<T, AT>::dr_vector_engine()
	{

	}

	template<class T, class AT>
	dr_vector_engine<T, AT>::dr_vector_engine(dr_vector_engine&&) noexcept
	{

	}

	template<class T, class AT>
	dr_vector_engine<T, AT>::dr_vector_engine(const dr_vector_engine&)
	{

	}

	template<class T, class AT>
	template<class U>
	dr_vector_engine<T, AT>::dr_vector_engine(initializer_list<U> list)
	{

	}

	template<class T, class AT>
	dr_vector_engine<T, AT>::dr_vector_engine(dr_vector_engine::size_type elems)
	{

	}

	template<class T, class AT>
	dr_vector_engine<T, AT>::dr_vector_engine(dr_vector_engine::size_type elems, dr_vector_engine::size_type elem_cap)
	{

	}

	template<class T, class AT>
	dr_vector_engine<T, AT>& dr_vector_engine<T, AT>::operator=(dr_vector_engine<T, AT>&& rhs) noexcept
	{
		return *this;
	}

	template<class T, class AT>
	dr_vector_engine<T, AT>& dr_vector_engine<T, AT>::operator=(const dr_vector_engine<T, AT>& rhs)
	{
		return *this;
	}

	template<class T, class AT>
	template<class ET2>
	dr_vector_engine<T, AT>& dr_vector_engine<T, AT>::operator=(const ET2& rhs)
	{
		return *this;
	}

	template<class T, class AT>
	typename dr_vector_engine<T, AT>::iterator dr_vector_engine<T, AT>::begin() noexcept
	{
		return nullptr;
	}

	template<class T, class AT>
	typename dr_vector_engine<T, AT>::iterator dr_vector_engine<T, AT>::end() noexcept
	{
		return nullptr;
	}

	template<class T, class AT>
	typename dr_vector_engine<T, AT>::const_iterator dr_vector_engine<T, AT>::begin() const noexcept
	{
		return nullptr;
	}

	template<class T, class AT>
	typename dr_vector_engine<T, AT>::const_iterator dr_vector_engine<T, AT>::end() const noexcept
	{
		return nullptr;
	}

	template<class T, class AT>
	typename dr_vector_engine<T, AT>::const_iterator dr_vector_engine<T, AT>::cbegin() const noexcept
	{
		return nullptr;
	}

	template<class T, class AT>
	typename dr_vector_engine<T, AT>::const_iterator dr_vector_engine<T, AT>::cend() const noexcept
	{
		return nullptr;
	}

	template<class T, class AT>
	typename dr_vector_engine<T, AT>::size_type dr_vector_engine<T, AT>::capacity() const noexcept
	{
		return 0;
	}

	template<class T, class AT>
	typename dr_vector_engine<T, AT>::size_type dr_vector_engine<T, AT>::elements() const noexcept
	{
		return 0;
	}

	template<class T, class AT>
	void dr_vector_engine<T, AT>::reserve(dr_vector_engine::size_type cap)
	{

	}

	template<class T, class AT>
	void dr_vector_engine<T, AT>::resize(dr_vector_engine::size_type elems)
	{

	}

	template<class T, class AT>
	void dr_vector_engine<T, AT>::resize(dr_vector_engine::size_type elems, dr_vector_engine::size_type cap)
	{

	}

	template<class T, class AT>
	typename dr_vector_engine<T, AT>::reference dr_vector_engine<T, AT>::operator()(dr_vector_engine::size_type i)
	{
		return ;
	}

	template<class T, class AT>
	typename dr_vector_engine<T, AT>::const_reference dr_vector_engine<T, AT>::operator()(dr_vector_engine::size_type i) const
	{
		return ;
	}

	template<class T, class AT>
	void dr_vector_engine<T, AT>::swap(dr_vector_engine& rhs) noexcept
	{

	}

	template<class T, class AT>
	void dr_vector_engine<T, AT>::swap_elements(dr_vector_engine::size_type i, dr_vector_engine::size_type j) noexcept
	{

	}
}