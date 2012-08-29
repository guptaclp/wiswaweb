/*
 * This file is part of the Code::Blocks IDE and licensed under the GNU Lesser General Public License, version 3
 * http://www.gnu.org/licenses/lgpl-3.0.html
 */

#ifndef REPLACEDLG_H
#define REPLACEDLG_H

#include "findreplacebase.h"

class wxComboBox;
class wxCommandEvent;
class wxNotebookEvent;
class wxActivateEvent;

class ReplaceDlg : public FindReplaceBase
{
    public:
        ReplaceDlg(wxWindow* parent, const wxString& initial = wxEmptyString, bool hasSelection = false,
                   bool replaceInFilesOnly = false, bool replaceInFilesActive = false);
        ~ReplaceDlg();

        wxString GetFindString() const;
        wxString GetReplaceString() const;
        bool IsFindInFiles() const;
        bool GetDeleteOldSearches() const;
        bool GetSortSearchResult() const;
        bool GetMatchWord() const;
        bool GetStartWord() const;
        bool GetMatchCase() const;
        bool GetRegEx() const;
        bool GetAutoWrapSearch() const;
        bool GetFindUsesSelectedText() const;
        bool GetStartFile() const;
        bool GetFixEOLs() const;

        int GetDirection() const;
        int GetOrigin() const;
        int GetScope() const;
        bool GetRecursive() const;      // for find in search path
        bool GetHidden() const;         // for find in search path
        wxString GetSearchPath() const; // for find in search path
        wxString GetSearchMask() const; // for find in search path

        bool IsMultiLine() const;

    protected:
        void OnReplaceChange(wxNotebookEvent& event);
        void OnRegEx(wxCommandEvent& event);
        void OnActivate(wxActivateEvent& event);
        void OnMultiChange(wxCommandEvent& event);
        void OnLimitToChange(wxCommandEvent& event);

    private:
        void FillComboWithLastValues(wxComboBox* combo, const wxString& configKey);
        void SaveComboValues(wxComboBox* combo, const wxString& configKey);

        bool m_ReplaceInFilesActive;

        DECLARE_EVENT_TABLE()
};

#endif // REPLACEDLG_H