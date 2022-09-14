#include <iostream>
using namespace std;
#include "polimorfismo_general.h"

//++++++++++++++++++++++
// polimorfismo_general
//+++++++++++++++++++++++
polimorfismo_general::polimorfismo_general(void)
{

}//______________________________________________

polimorfismo_general::~polimorfismo_general(void)
{

}//______________________________________________

void polimorfismo_general::mensaje(void)
{
  cout << "Mensaje en base de jerarquía" << endl;
}//______________________________________________

//++++++++++++++++++++++
// herencia1
//+++++++++++++++++++++++

herencia1::herencia1(void)
{

}//______________________________________________

void herencia1::mensaje(void)
{
  cout << "Mensaje nivel herenicia tipo 1" << endl;
}//______________________________________________

//++++++++++++++++++++++
// herencia2
//+++++++++++++++++++++++

herencia2::herencia2(void)
{

}//______________________________________________

void herencia2::mensaje(void)
{
  cout << "Mensaje nivel herenicia tipo 2" << endl;
}//______________________________________________


//++++++++++++++++++++++
// herencia3
//+++++++++++++++++++++++

herencia3::herencia3(void)
{

}//______________________________________________

void herencia3::mensaje(void)
{
  cout << "Mensaje nivel herenicia tipo 3" << endl;
}//______________________________________________
