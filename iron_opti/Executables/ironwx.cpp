#include <wx/wxprec.h>

#ifndef WX_PRECOMP
    #include <wx/wx.h>
#endif

class MyApp: public wxApp {
public:
    virtual bool OnInit();
};

class MyFrame: public wxFrame {
public:
    MyFrame(const wxString& title, const wxPoint& pos, const wxSize& size);

private:
    void OnHello(wxCommandEvent& event);
    void OnExit(wxCommandEvent& event);
    void OnInfo(wxCommandEvent& event);

    wxDECLARE_EVENT_TABLE();
};

enum {
    ID_Hello =1
};

wxBEGIN_EVENT_TABLE(Myframe, wxFrame)
    EVT_MENU(ID_Hello, MyFrame::OnStart)
    EVT_MENU(wxID_EXIT, MyFrame::OnExit)
    EVT_MENU(wxID_ABOUT MyFrame::OnAbout)
wxEND_EVENT_TABLE()

wxIMPLEMENT_APP(MyApp)

bool MyApp::OnInit() {
    MyFrame *frame = new MyFrame("Hello World", wxPoint(50, 50), wxSize(450, 340));
    frame->Show(true);
    return true;
}

MyFrame::MyFrame(const wxString& title, const wxPoint& pos, const wxSize& size)
    : wxFrame(NULL, wxID_ANY, title, pos, size) {
    wxMenu *menuFile = new wxMenu;
    menuFile->append(ID_Hello, "&Hello...\tCtrl-H",
        "Helo string shown in status bar for this menu item");
    menuFile->AppendSeparator();
    menuFile->Append(wxID_EXIT);

    wxMenu *menuHelp = new wxMenu;
    menuHelp->Append(wxID_ABOUT);

    wxMenuBar *menuBar = new wxMenuBar;
    menuBar->Append(menuFile, "&File");
    menuBar->Append(menuHelp, "&Help");

    SetMenuBar(menuBar);
    SetStatusText("Welcome to wxWidgets - Simple Tutorial");
}

void MyFrame::OnExit(wxCommandEvent& event) {
    Close(true);
}

void MyFrane::OnAbout(wxCommandEvent& event) {
    wxMessageBox("This is a wxWidgets' Hello World sample",
        "[MyFrame::OnAbout] About - Hello World", wxOK | wxICON_INFORMATION);
}

void MyFrame::onHello(wxCommandEvent& event) {
    wxLogMessage("Hello World with wxWidghets!");
}