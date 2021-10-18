// ============================================================================
// File: cpersoninfo.h
// ============================================================================
// Header file for the CPersonInfo
// ============================================================================

#ifndef CPERSONINFO_H
#define CPERSONINFO_H

template <class T>
class   CPersonInfo
{
	public:
    	// constructors
    	CPersonInfo();
    	CPersonInfo(const CPersonInfo  &other);
		CPersonInfo(T weight, T height, int age, std::string fullName);
		~CPersonInfo();

    	// member functions
    	T     		GetWeight() const;
    	T     		GetHeight() const;
    	int     	GetAge() const;
		std::string	GetName() const;
		int			GetNameLength() const;
    	void    	SetWeight(T weight);
    	void    	SetHeight(T height);
    	void		SetAge(int  age);
		void		SetName(std::string fullName);

	private:
   		T m_weight; // pounds
   		T m_height; // inches
   		int *m_age; // years
   		std::string m_fullName;
};

#endif  // CPERSONINFO_H

// ============================================================================
// Include the implementation of cpersoninfo.tpp in the header file
// ============================================================================
#include "cpersoninfo.tpp"