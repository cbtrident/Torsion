/////////////////////////////////////////////////////////////////////////////
// Name:        checkbox.h
// Purpose:     wxCheckBox class
// Author:      Julian Smart
// Modified by:
// Created:     17/09/98
// RCS-ID:      $Id: checkbox.h,v 1.18 2004/06/05 21:01:00 MBN Exp $
// Copyright:   (c) Julian Smart
// Licence:   	wxWindows licence
/////////////////////////////////////////////////////////////////////////////

#ifndef _WX_CHECKBOX_H_
#define _WX_CHECKBOX_H_

#if defined(__GNUG__) && !defined(NO_GCC_PRAGMA)
#pragma interface "checkbox.h"
#endif

// Checkbox item (single checkbox)
class WXDLLEXPORT wxCheckBox: public wxCheckBoxBase
{
    DECLARE_DYNAMIC_CLASS(wxCheckBox)
        
public:
    inline wxCheckBox() { Init(); }
    inline wxCheckBox(wxWindow *parent, wxWindowID id, const wxString& label,
        const wxPoint& pos = wxDefaultPosition,
        const wxSize& size = wxDefaultSize, long style = 0,
        const wxValidator& validator = wxDefaultValidator,
        const wxString& name = wxCheckBoxNameStr)
    {
        Init();

        Create(parent, id, label, pos, size, style, validator, name);
    }
    
    bool Create(wxWindow *parent, wxWindowID id, const wxString& label,
        const wxPoint& pos = wxDefaultPosition,
        const wxSize& size = wxDefaultSize, long style = 0,
        const wxValidator& validator = wxDefaultValidator,
        const wxString& name = wxCheckBoxNameStr);
    virtual void SetValue(bool);
    virtual bool GetValue() const ;
    virtual void Command(wxCommandEvent& event);
    
    // Implementation
    virtual void ChangeBackgroundColour();
private:
    // common part of all constructors
    void Init()
    {
        m_evtType = wxEVT_COMMAND_CHECKBOX_CLICKED;
    }

    virtual void DoSet3StateValue(wxCheckBoxState state);

    virtual wxCheckBoxState DoGet3StateValue() const;

    // public for the callback
public:
    // either exEVT_COMMAND_CHECKBOX_CLICKED or ..._TOGGLEBUTTON_CLICKED
    wxEventType m_evtType;
};

#endif
// _WX_CHECKBOX_H_
