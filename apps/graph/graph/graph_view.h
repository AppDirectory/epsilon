#ifndef GRAPH_GRAPH_VIEW_H
#define GRAPH_GRAPH_VIEW_H

#include <escher.h>
#include "banner_view.h"
#include "../../cursor_view.h"
#include "graph_window.h"
#include "../../curve_view_with_banner.h"
#include "../../constant.h"
#include "../function_store.h"
#include "../local_context.h"

namespace Graph {

class GraphView : public CurveViewWithBanner {
public:
  GraphView(FunctionStore * functionStore, GraphWindow * graphWindow);
  View * bannerView() override;
  void drawRect(KDContext * ctx, KDRect rect) const override;
  void setContext(Context * context);
  Context * context() const;
  void reload();
  void reloadSelection() override;
  void layoutSubviews() override;
private:
  constexpr static KDColor k_gridColor = KDColor::RGB24(0xEEEEEE);
  constexpr static KDCoordinate k_cursorSize = 9;

  int numberOfSubviews() const override;
  View * subviewAtIndex(int index) override;

  char * label(Axis axis, int index) const override;
  float evaluateModelWithParameter(Model * expression, float abscissa) const override;
  void drawGrid(KDContext * ctx, KDRect rect) const;
  void drawGridLines(KDContext * ctx, KDRect rect, Axis axis, float step, KDColor color) const;

  BannerView m_bannerView;
  CursorView m_cursorView;

  char m_xLabels[k_maxNumberOfXLabels][Constant::FloatBufferSizeInScientificMode];
  char m_yLabels[k_maxNumberOfYLabels][Constant::FloatBufferSizeInScientificMode];

  GraphWindow * m_graphWindow;
  FunctionStore * m_functionStore;
  Context * m_context;
};

}

#endif
