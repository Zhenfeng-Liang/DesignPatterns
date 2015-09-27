
// Note: Note that if we were defining a new class, we would probably put this registration
// in the source file for the class but as we have already defined the call and
// put classes, we do not do so here.

// Note: Two global variables initialized at the beginning of the program
//

#include "PayOffConstructible.h"

namespace
{ // unnamed namespace, invisible to the rest of the program, independent with other files in this program

	PayOffHelper<PayOffCall> RegisterCall("call");
	PayOffHelper<PayOffPut> RegisterPut("put");
}