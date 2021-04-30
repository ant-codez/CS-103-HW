// ============================================================================
// File: CPlayer.cpp
// ============================================================================
// This is an implementation file for the CPlayer class.
// ============================================================================

#include <iostream>
#include <cstring>
#include <unistd.h>   // sleep function
#include "CPlayer.h"
using namespace std;



// ==== CPlayer::CPlayer ======================================================
//
// This is the CPlayer default constructor. It allocates space from the HEAP and
// initializes the private data member m_name to "Guest Player". Futhermore, it
// sets m_gameResetted to false.
//
// Input:
//      None
//
// ============================================================================





// ==== CPlayer::CPlayer ======================================================
//
// This is the CPlayer type constructor. It uses the parameter to allocate space
// from the HEAP and initialize the private data member m_name.  Futhermore, it
// sets m_gameResetted to false.
//
// Input:
//      name    [IN]    -- a char pointer to a given name
//
// ============================================================================


    



// ==== CPlayer::~CPlayer =====================================================
//
// This is the CPlayer destructor. It appropriately releases memory from the
// HEAP.
//
// Input:
//      None
//
// ============================================================================





// ==== CPlayer::SetName ======================================================
//
// The SetName function uses the parameter to update the private data member
// m_name. Be sure you have exactly the space needed to store the new name.
//
// Input:
//      name    [IN]    -- a char pointer to a given name
//
// Output:
//      None
//
// ============================================================================





// ==== CPlayer::GetName ======================================================
//
// The GetName function returns m_name as a const char pointer.
//
// Input:
//      None
//
// Output:
//      A const char*
//
// ============================================================================





// ==== CPlayer::Start ========================================================
//
// The Start function uses the CSnowmanGame object to begin the game by calling
// its public member function Start. Before calling the Start function and if
// the game has not been resetted, the program will display a welcoming message
// and a game loading message. Afterwards the program will sleep for
// SLEEP_NUM_PLAYER seconds.
//
// Input:
//      None
//
// Output:
//      None
//
// ============================================================================





// ==== CPlayer::Reset ========================================================
//
// The Reset function uses the CSnowmanGame object to restart the game by
// calling its public member function Reset. Before calling the Reset function
// the program will display a restarting and reloading message. Afterwards the
// program will sleep for SLEEP_NUM_PLAYER seconds.
//
// Input:
//      None
//
// Output:
//      None
//
// ============================================================================


