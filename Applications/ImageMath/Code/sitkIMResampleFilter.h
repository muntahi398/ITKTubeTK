#ifndef __sitkIMResampleFilter_h
#define __sitkIMResampleFilter_h

#include "SimpleITK.h"

#include "sitkDualImageFilter.h"


namespace sitkIM
{

class ResampleFilter : public itk::simple::DualImageFilter
{
public:
  typedef ResampleFilter Self;

  /** Default Constructor */
  ResampleFilter();

  /** Declare the types of pixels this filter will work on */
  typedef itk::simple::BasicPixelIDTypeList  PixelIDTypeList;

  /** Print outselves out */
  std::string ToString() const;


  /** Execute the filter */
  itk::simple::Image* Execute(itk::simple::Image* image1,
                              itk::simple::Image* image2);

private:

  /** Set up the member functions for the member function factory */
  typedef itk::simple::Image* (Self::*MemberFunctionType)(
                                            itk::simple::Image*,
                                            itk::simple::Image* );

  /** Internal execute method that can access the ITK images */
  template <class TImageType> itk::simple::Image* ExecuteInternal(
                                            itk::simple::Image* image1,
                                            itk::simple::Image* image2 );

  /** Member function addressor */
  friend struct itk::simple::detail::MemberFunctionAddressor<MemberFunctionType>;
    std::auto_ptr<itk::simple::detail::MemberFunctionFactory<MemberFunctionType> > m_MemberFactory;

};

} // end namespace sitkIM
#endif
