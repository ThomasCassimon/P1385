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
		using engine_category = resizable_vector_engine_tag;
		using element_type = T;
		using value_type = remove_cv_t<T>;
		using allocator_type = AT;
		using pointer = typename allocator_traits<AT>::pointer;
		using const_pointer = typename allocator_traits<AT>::const_pointer;
		using reference = element_type&;
		using const_reference = const element_type&;
		using difference_type = ptrdiff_t;
		using size_type = size_t;
		// todo: These 2 are implementation defined, check if there's a better type for this
		using iterator = pointer;
		using const_iterator = const_pointer;

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

		dr_vector_engine& operator=(dr_vector_engine&& rhs) noexcept;
		dr_vector_engine& operator=(const dr_vector_engine& rhs);

		template <class ET2>
		dr_vector_engine& operator=(const ET2& rhs);

		//-	Iterators
		//
		iterator begin() noexcept;
		iterator end() noexcept;
		const_iterator begin() const noexcept;
		const_iterator end() const noexcept;
		const_iterator cbegin() const noexcept;
		const_iterator cend() const noexcept;

		//-	Capacity
		//
		[[nodiscard]] size_type capacity() const noexcept;
		[[nodiscard]] size_type elements() const noexcept;

		void reserve(size_type cap);
		void resize(size_type elems);
		void resize(size_type elems, size_type cap);

		//-	Element access
		reference operator()(size_type i);
		const_reference operator()(size_type i) const;

		//- Modifiers
		//
		void swap(dr_vector_engine& rhs) noexcept;
		void swap_elements(size_type i, size_type j) noexcept;

		private:
		constexpr static size_type DEFAULT_SIZE_ = 3;

		allocator_type alloc_;
		pointer data_;
		size_type elems_;
		size_type cap_;
	};

	template <class T, class AT>
	dr_vector_engine<T, AT>::~dr_vector_engine()
	{
		if ((0 < this->cap_) && (this->data_ != nullptr))
		{
			std::allocator_traits<AT>::deallocate(this->alloc_, this->data_, this->cap_);
		}
	}

	template <class T, class AT>
	dr_vector_engine<T, AT>::dr_vector_engine() : dr_vector_engine(0, DEFAULT_SIZE_)
	{
	}

	template <class T, class AT>
	dr_vector_engine<T, AT>::dr_vector_engine(dr_vector_engine&& other) noexcept
		: alloc_(std::move(other.alloc_)), data_(std::move(other.data_)), elems_(std::move(other.elems_)),
		  cap_(std::move(other.cap_))
	{
		other.alloc_ = AT();
		other.data_ = nullptr;
		other.elems_ = 0;
		other.cap_ = 0;
	}

	template <class T, class AT>
	dr_vector_engine<T, AT>::dr_vector_engine(const dr_vector_engine<T, AT>& other)
		: alloc_(other.alloc_), data_(std::allocator_traits<AT>::allocate(this->alloc_, other.cap_)),
		  elems_(other.elems_), cap_(other.cap_)
	{
		for (size_type i = 0; i < this->elems_; ++i)
		{
			std::allocator_traits<AT>::construct(this->alloc_, &this->data_[i], other.data_[i]);
		}
	}

	template <class T, class AT>
	template <class U>
	dr_vector_engine<T, AT>::dr_vector_engine(initializer_list<U> list) : dr_vector_engine<T, AT>(list.size())
	{
		std::copy_n(list.begin(), list.size(), this->data_);
	}

	template <class T, class AT>
	dr_vector_engine<T, AT>::dr_vector_engine(dr_vector_engine::size_type elems) : dr_vector_engine(elems, elems)
	{
	}

	template <class T, class AT>
	dr_vector_engine<T, AT>::dr_vector_engine(dr_vector_engine::size_type elems, dr_vector_engine::size_type elem_cap)
		: alloc_(), data_(std::allocator_traits<AT>::allocate(this->alloc_, elem_cap)), elems_(elems), cap_(elem_cap)
	{
		for (std::size_t i = 0; i < this->elems_; ++i)
		{
			std::allocator_traits<AT>::construct(this->alloc_, &this->data_[i], T{});
		}
	}

	template <class T, class AT>
	dr_vector_engine<T, AT>& dr_vector_engine<T, AT>::operator=(dr_vector_engine<T, AT>&& rhs) noexcept
	{
		return *this;
	}

	template <class T, class AT>
	dr_vector_engine<T, AT>& dr_vector_engine<T, AT>::operator=(const dr_vector_engine<T, AT>& rhs)
	{
		return *this;
	}

	template <class T, class AT>
	template <class ET2>
	dr_vector_engine<T, AT>& dr_vector_engine<T, AT>::operator=(const ET2& rhs)
	{
		return *this;
	}

	template <class T, class AT>
	typename dr_vector_engine<T, AT>::iterator dr_vector_engine<T, AT>::begin() noexcept
	{
		return nullptr;
	}

	template <class T, class AT>
	typename dr_vector_engine<T, AT>::iterator dr_vector_engine<T, AT>::end() noexcept
	{
		return nullptr;
	}

	template <class T, class AT>
	typename dr_vector_engine<T, AT>::const_iterator dr_vector_engine<T, AT>::begin() const noexcept
	{
		return nullptr;
	}

	template <class T, class AT>
	typename dr_vector_engine<T, AT>::const_iterator dr_vector_engine<T, AT>::end() const noexcept
	{
		return nullptr;
	}

	template <class T, class AT>
	typename dr_vector_engine<T, AT>::const_iterator dr_vector_engine<T, AT>::cbegin() const noexcept
	{
		return nullptr;
	}

	template <class T, class AT>
	typename dr_vector_engine<T, AT>::const_iterator dr_vector_engine<T, AT>::cend() const noexcept
	{
		return nullptr;
	}

	template <class T, class AT>
	typename dr_vector_engine<T, AT>::size_type dr_vector_engine<T, AT>::capacity() const noexcept
	{
		return this->cap_;
	}

	template <class T, class AT>
	typename dr_vector_engine<T, AT>::size_type dr_vector_engine<T, AT>::elements() const noexcept
	{
		return this->elems_;
	}

	template <class T, class AT>
	void dr_vector_engine<T, AT>::reserve(dr_vector_engine::size_type cap)
	{
	}

	template <class T, class AT>
	void dr_vector_engine<T, AT>::resize(dr_vector_engine::size_type elems)
	{
	}

	template <class T, class AT>
	void dr_vector_engine<T, AT>::resize(dr_vector_engine::size_type elems, dr_vector_engine::size_type cap)
	{
	}

	template <class T, class AT>
	typename dr_vector_engine<T, AT>::reference dr_vector_engine<T, AT>::operator()(dr_vector_engine::size_type i)
	{
		return this->data_[i];
	}

	template <class T, class AT>
	typename dr_vector_engine<T, AT>::const_reference
	dr_vector_engine<T, AT>::operator()(dr_vector_engine::size_type i) const
	{
		return this->data_[i];
	}

	template <class T, class AT>
	void dr_vector_engine<T, AT>::swap(dr_vector_engine& rhs) noexcept
	{
	}

	template <class T, class AT>
	void dr_vector_engine<T, AT>::swap_elements(dr_vector_engine::size_type i, dr_vector_engine::size_type j) noexcept
	{
	}
}