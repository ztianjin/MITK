/*===================================================================

The Medical Imaging Interaction Toolkit (MITK)

Copyright (c) German Cancer Research Center,
Division of Medical and Biological Informatics.
All rights reserved.

This software is distributed WITHOUT ANY WARRANTY; without
even the implied warranty of MERCHANTABILITY or FITNESS FOR
A PARTICULAR PURPOSE.

See LICENSE.txt or http://www.mitk.org for details.

===================================================================*/


#ifndef LISTENERVIEW_H_
#define LISTENERVIEW_H_

// berry Includes
#include <berryQtViewPart.h>
#include <berryIStructuredSelection.h>
#include <berryISelectionListener.h>

// ui Includes
#include "ui_ListenerViewControls.h"

 /** Documentation:
  *   \ingroup org_mitk_example_gui_selectionserviceqt
  *
  *   \brief This BlueBerry view is part of the BlueBerry example
  *   "Selection service QT". It creates two radio buttons that listen
  *   for selection events of the Qlistwidget (SelectionProvider) and
  *   change the radio button state accordingly.
  *
  * @see SelectionView
  *
  */
class ListenerView : public berry::QtViewPart
{

  Q_OBJECT

public:

  static const std::string VIEW_ID;

  ListenerView();

  virtual ~ListenerView();

  virtual void CreateQtPartControl(QWidget *parent);

private:
    //! [Qt Selection Listener method and pointer]
    /** @brief Method of berry::ISelectionListener that implements the selection listener functionality.
      * @param sourcepart The workbench part  responsible for the selection change.
      * @param selection This parameter holds the current selection.
      *
      * @see ISelectionListener
      *
      */
    void SelectionChanged(berry::IWorkbenchPart::Pointer sourcepart,
                     berry::ISelection::ConstPointer selection);

    /** @brief this pointer holds the selection listener*/
    berry::ISelectionListener::Pointer m_SelectionListener;
    //! [Qt Selection Listener method and pointer]

    friend struct berry::SelectionChangedAdapter<ListenerView>;

  private slots:
    /** @brief Simple slot function that changes the selection of the radio buttons according to the passed string.
      * @param selectStr QString that contains the name of the slected list element
      *
      */
    void ToggleRadioMethod(QString selectStr);

protected:
  /** @brief this pointer holds the current selection*/
  berry::IStructuredSelection::ConstPointer m_CurrentSelection;

  void SetFocus();

  Ui::ListenerViewControls m_Controls;

  QWidget* m_Parent;

};

#endif /*LISTENERVIEW_H_*/
