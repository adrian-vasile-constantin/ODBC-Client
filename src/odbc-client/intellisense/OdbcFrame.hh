#if !defined ODBC_CLIENT_ODBC_FRAME_HH
#define ODBC_CLIENT_ODBC_FRAME_HH

class OdbcFrame: public wxFrame
{
public:
    OdbcFrame();

private:
    auto OnConnect(wxCommandEvent &event) -> void;
    auto OnExit(wxCommandEvent &event) -> void;
    auto OnAbout(wxCommandEvent &event) -> void;
};

#endif	    // #if !defined ODBC_CLIENT_ODBC_FRAME_HH
