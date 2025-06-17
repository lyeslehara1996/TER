#ifndef OPERATION_HPP
#define OPERATION_HPP

#include <functional>

float addition(float a, float b);
float soustraction(float a, float b);
float multiplication(float a, float b);
float division(float a, float b);

// Fonctions d'affichage
void afficheOperation(float x, float y, float (*operation)(float, float));
void afficheOperationF(float x, float y, std::function<float(float, float)> operation);

#endif // OPERATIONS_HPP