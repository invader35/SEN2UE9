///////////////////////////////////////
// Workfile    : GenericCombine.h
// Author      : Matthias Schett
// Date        : 27-05-2013
// Description : Combine if template
// Remarks     : -
// Revision    : 0
///////////////////////////////////////

//************************************
// Method:    combine_if
// FullName:  combine_if
// Access:    public 
// Returns:   void
// Qualifier:
// Parameter: InputItor1 first1
// Parameter: InputItor1 end1
// Parameter: InputItor2 first2
// Parameter: OutputItor res
// Parameter: CombineOp combOp
// Parameter: Pred p
// Combines to container, all three container have to be of the same size
//************************************
template<typename InputItor1, typename InputItor2, typename OutputItor, typename CombineOp, typename Pred>
void combine_if(InputItor1 first1, InputItor1 end1, InputItor2 first2, OutputItor res, CombineOp combOp, Pred p);

//************************************
// Method:    Print
// FullName:  Print
// Access:    public 
// Returns:   void
// Qualifier:
// Parameter: Container const & coll
// Parameter: std::string header
// Parameter: std::ostream & os
// Prints a container with the specified header to the specified ostream
//************************************
template <typename Container>
void Print(Container const& coll, std::string header = "", std::ostream &os = std::cout );

#include "GenericCombine.impl"