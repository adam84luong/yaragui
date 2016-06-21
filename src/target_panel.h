#ifndef __TARGET_PANEL_H__
#define __TARGET_PANEL_H__

#include "ui_target_panel.h"
#include "file_stats.h"
#include <vector>

class TargetPanel : public QWidget
{
  Q_OBJECT

public:

  TargetPanel(QWidget* parent);

  void show(FileStats::Ref stats);

private slots:

  void showHistogram();
  void showLineGraph();

private:

  enum ViewMode
  {
    ViewModeHistogram,
    ViewModeLineGraph
  };

  void renderView();
  void renderHistogram();
  void renderLineGraph();

  void prepareHistogram();

  virtual void resizeEvent(QResizeEvent* event);

  Ui::TargetPanel m_ui;
  FileStats::Ref m_stats;

  ViewMode m_viewMode;
  QAction* m_histogramButton;
  QAction* m_lineGraphButton;

  std::vector<int> m_histogramBuffer;
  QPixmap m_histogramPixmap;

};

#endif // __TARGET_PANEL_H__
