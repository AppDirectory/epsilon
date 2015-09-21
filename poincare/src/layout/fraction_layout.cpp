#include <poincare/fraction.h>
#include <string.h>
#include "fraction_layout.h"

static inline KDCoordinate max(KDCoordinate a, KDCoordinate b) {
  return (a > b ? a : b);
}

#define FRACTION_BORDER_LENGTH 2
#define FRACTION_LINE_MARGIN 2
#define FRACTION_LINE_HEIGHT 1

FractionLayout::FractionLayout(Expression * numerator, Expression * denominator) {
  m_numerator = numerator->createLayout();
  m_denominator = denominator->createLayout();
}

ExpressionLayout * FractionLayout::child(uint16_t index) {
  switch (index) {
    case 0:
      return m_numerator;
    case 1:
      return m_denominator;
    default:
      return nullptr;
  }
}

void FractionLayout::positionChildren() {
  /*
  m_numerator->m_frame.origin.x = (KDCoordinate)((m_frame.width - numFrame.width)/2);
  m_numerator->m_frame.origin.y = 0;

  m_denominator->m_frame.origin.x = (KDCoordinate)((m_frame.width - denFrame.width)/2);
  m_denominator->m_frame.origin.y = (KDCoordinate)(numFrame.height + 2*FRACTION_LINE_MARGIN + FRACTION_LINE_HEIGHT);
  */
}

void FractionLayout::computeSize() {
  /*
  m_frame.width = max(numFrame.width, denFrame.width) + 2*FRACTION_BORDER_LENGTH;
  m_frame.height = numFrame.height + FRACTION_LINE_MARGIN + FRACTION_LINE_HEIGHT + FRACTION_LINE_MARGIN + denFrame.height;
  */
}


void FractionLayout::draw() {
  m_numerator->draw();
  m_denominator->draw();

  KDCoordinate fractionLineY = m_numerator->m_frame.height + FRACTION_LINE_MARGIN;

  KDDrawLine((KDPoint){.x = 0, .y = fractionLineY},
      (KDPoint){.x = m_frame.width, .y = fractionLineY});
}