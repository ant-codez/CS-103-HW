// ============================================================================
// File: cpersoninfo.tpp
// ============================================================================
// This is the implementation file for cpersoninfo.
// ============================================================================

// ==== Default Constructor ===================================================
//
// The default constructor sets everything to zero and m_fullName to an empty
// string.
//
// Input:
//		nothing
//
// Output:
//      nothing
//
// ============================================================================
template <class T>
CPersonInfo<T>::CPersonInfo() {
    m_weight = 0;
    m_height = 0;

    m_age = new int;
    *m_age = 0;

    m_fullName = "";
}


// ==== Copy Constructor ======================================================
//
// The copy constructor copies all the elements from the other object.
//
// Input:
//		nothing
//
// Output:
//      nothing
//
// ============================================================================
template <class T>
CPersonInfo<T>::CPersonInfo(const CPersonInfo &cpy) {
    m_weight = cpy.m_weight;
    m_height = cpy.m_height;
    
    m_age = new int;
    *m_age = cpy.GetAge();
    
    m_fullName = cpy.m_fullName;
}


// ==== Type Constructor ======================================================
//
// The type constructor assigns the values passed as arguments during
// declaration
//
// Input:
//		nothing
//
// Output:
//      nothing
//
// ============================================================================
template <class T>
CPersonInfo<T>::CPersonInfo(T weight, T height, int age, std::string fullName) {
    m_weight = weight;
    m_height = height;
    
    m_age = new int;
    *m_age = age;
    
    m_fullName = fullName;

}


// ==== Destructor ============================================================
//
// The destructor releases m_age back to the HEAP.
//
// Input:
//		nothing
//
// Output:
//      nothing
//
// ============================================================================
template <class T>
CPersonInfo<T>::~CPersonInfo() {
    delete m_age;
}



// ==== GetWeight =============================================================
//
// The function returns the weight to the caller.
//
// Input:
//		void
//
// Output:
//      T data type (template)
//
// ============================================================================
template <class T>
T CPersonInfo<T>::GetWeight() const {
    return m_weight;
}



// ==== GetHeight =============================================================
//
// The function returns the height to the caller.
//
// Input:
//		void
//
// Output:
//      T data type (template)
//
// ============================================================================
template <class T>
T CPersonInfo<T>::GetHeight() const {
    return m_height;
}



// ==== GetAge ================================================================
//
// The function returns the age to the caller.
//
// Input:
//		void
//
// Output:
//      int
//
// ============================================================================
template <class T>
int CPersonInfo<T>::GetAge() const {
    return *m_age;
}



// ==== GetName ===============================================================
//
// The function returns the name to the caller.
//
// Input:
//		void
//
// Output:
//      string data type
//
// ============================================================================
template <class T>
std::string CPersonInfo<T>::GetName() const {
    return m_fullName;
}



// ==== GetNameLength =========================================================
//
// The function returns the number of characters in their name(s) (does not
// include the spaces between their name(s) )
//
// Input:
//		void
//
// Output:
//      int
//
// ============================================================================
template <class T>
int CPersonInfo<T>::GetNameLength() const {
    return m_fullName.length();
}



// ==== SetWeight =============================================================
//
// The function assigns the weight to the private data member.
//
// Input:
//		weight  [IN]  -- A T data type (template)
//
// Output:
//      void
//
// ============================================================================
template <class T>
void CPersonInfo<T>::SetWeight(T weight) {
    m_weight = weight;
}



// ==== SetHeight =============================================================
//
// The function assigns the height to the private data member.
//
// Input:
//		height  [IN]  -- A T data type (template)
//
// Output:
//      void
//
// ============================================================================
template <class T>
void CPersonInfo<T>::SetHeight(T height) {
    m_height = height;
}



// ==== SetAge ================================================================
//
// The function assigns the age to the private data member.
//
// Input:
//		age [IN]  -- An int data type
//
// Output:
//      void
//
// ============================================================================
template <class T>
void CPersonInfo<T>::SetAge(int Age) {
    *m_age = Age;
}



// ==== SetName ===============================================================
//
// The function assigns the name to the private data member.
//
// Input:
//		name [IN]  -- A string data type
//
// Output:
//      void
//
// ============================================================================
template <class T>
void CPersonInfo<T>::SetName(std::string fullName) {
    m_fullName = fullName;
}