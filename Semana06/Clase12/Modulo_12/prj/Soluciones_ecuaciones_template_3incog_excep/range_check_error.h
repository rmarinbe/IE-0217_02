#ifndef RANGE_CHECK_ERROR_H_INCLUDED
#define RANGE_CHECK_ERROR_H_INCLUDED
class _range_check_error : public _exception{
public:
  inline _range_check_error(void):_exception("Range check error:")
  {}//______________________________________________________________

  inline ~_range_check_error()
  {}//______________________________________________________________

  inline void getMessage(void)
  {
    cout << msg << "Index out of range" << endl;
  }//______________________________________________________________
};//______________________________________________________________


#endif // RANGE_CHECK_ERROR_H_INCLUDED
