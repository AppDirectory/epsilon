#include <quiz.h>
#include <poincare.h>
#include <ion.h>
#include <cmath>
#include <assert.h>
#include "helper.h"

using namespace Poincare;

QUIZ_CASE(poincare_parser) {
  Complex<double> a[1] = {Complex<double>::Float(1.2*M_E)};
  assert_parsed_expression_evaluate_to("1.2*X^(1)", a, 1);
  Complex<float> b[1] = {Complex<float>::Float(std::pow((float)M_E, 2.0f)*M_E)};
  assert_parsed_expression_evaluate_to("X^2*X^(1)", b, 1);
  Complex<double> c[1] = {Complex<double>::Float(2.0*std::pow(3.0, 4.0)+2.0)};
  assert_parsed_expression_evaluate_to("2*3^4+2", c, 1);
  Complex<float> d[1] = {Complex<float>::Float(-2.0f*std::pow(3.0f, 4.0f)+2.0f)};
  assert_parsed_expression_evaluate_to("-2*3^4+2", d,1);
  Complex<double> e[1] = {Complex<double>::Float(-std::sin(3.0)*2.0-3.0)};
  assert_parsed_expression_evaluate_to("-sin(3)*2-3", e, 1, Radian);
  Complex<float> f[1] = {Complex<float>::Float(-0.003f)};
  assert_parsed_expression_evaluate_to("-.003", f, 1);
  Complex<double> g[1] = {Complex<double>::Float(2.0)};
  assert_parsed_expression_evaluate_to(".02E2", g, 1);
  Complex<float> h[1] = {Complex<float>::Float(5.0f-2.0f/3.0f)};
  assert_parsed_expression_evaluate_to("5-2/3", h, 1);
  Complex<double> i[1] = {Complex<double>::Float(2.0/3.0-5.0)};
  assert_parsed_expression_evaluate_to("2/3-5", i, 1);
  Complex<float> j[1] = {Complex<float>::Float(-2.0f/3.0f-5.0f)};
  assert_parsed_expression_evaluate_to("-2/3-5", j, 1);
  Complex<double> k[1] = {Complex<double>::Float(std::sin(3.0)*2.0*(4.0+2.0))};
  assert_parsed_expression_evaluate_to("sin(3)2(4+2)", k, 1, Radian);
  Complex<float> l[1] = {Complex<float>::Float(4.0f/2.0f*(2.0f+3.0f))};
  assert_parsed_expression_evaluate_to("4/2*(2+3)", l, 1, Radian);
  Complex<double> m[1] = {Complex<double>::Float(4.0/2.0*(2.0+3.0))};
  assert_parsed_expression_evaluate_to("4/2*(2+3)", m, 1, Radian);
}
