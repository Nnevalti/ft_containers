#ifndef TYPE_TRAITS_HPP
# define TYPE_TRAITS_HPP

namespace ft
{
	// ENABLE_IF
	// Compile time constant of type bool
	// Prevent code from compiling if Cond is not met e.g is_integral
	template<bool Cond, class T = void> struct enable_if {};
	template<class T> struct enable_if<true, T> { typedef T type; };

	/*
	** IS_INTEGRAL
	** In C++ is integral actually inherits from true_type or false_type class :
	** template <class T> struct is_integral : public false_type {};
	** template <> struct is_integral<int> : public true_type {};
	**
	** True_type and false_type is a typedef of an integral_const instantiation :
	** typedef integral_constant<bool,true> true_type;
	**
	** Integral_const is defined like this in type_traits header :
	** template <class T, T v> struct integral_constant
	** {
	** 		static constexpr T value = v;
	** 		typedef T value_type;
	** 		typedef integral_constant<T,v> type;
	** 		constexpr operator T() { return v; }
	** };
	*/
	template <class T> struct is_integral { static const bool value = false; };
	template <> struct is_integral<bool> { static const bool value = true; };
	template <> struct is_integral<char> { static const bool value = true; };
	template <> struct is_integral<char16_t> { static const bool value = true; };
	template <> struct is_integral<char32_t> { static const bool value = true; };
	template <> struct is_integral<wchar_t> { static const bool value = true; };
	template <> struct is_integral<signed char> { static const bool value = true; };
	template <> struct is_integral<short int> { static const bool value = true; };
	template <> struct is_integral<int> { static const bool value = true; };
	template <> struct is_integral<long int> { static const bool value = true; };
	template <> struct is_integral<long long int> { static const bool value = true; };
	template <> struct is_integral<unsigned char> { static const bool value = true; };
	template <> struct is_integral<unsigned short int> { static const bool value = true; };
	template <> struct is_integral<unsigned int> { static const bool value = true; };
	template <> struct is_integral<unsigned long int> { static const bool value = true; };
	template <> struct is_integral<unsigned long long int> { static const bool value = true; };
	
}

#endif
