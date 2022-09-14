#ifndef POLIMORFISMO_GENERAL_H
#define POLIMORFISMO_GENERAL_H

class polimorfismo_general
{
  public:
    polimorfismo_general(void);
    virtual ~polimorfismo_general(void);
    virtual  void mensaje(void);
};

class herencia1 : public polimorfismo_general{
  public:
    herencia1(void);
    virtual  void mensaje(void);
};//____________________________________________________

class herencia2 : public polimorfismo_general{
  public:
    herencia2(void);
    virtual  void mensaje(void);

};//____________________________________________________

class herencia3 : public polimorfismo_general{
  public:
    herencia3(void);
    virtual  void mensaje(void);

};//____________________________________________________

#endif // POLIMORFISMO_GENERAL_H
