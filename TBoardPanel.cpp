#include "stdafx.h"
#include "TBoardPanel.h"

BEGIN_EVENT_TABLE(TBoardPanel, wxPanel)	
    EVT_PAINT(TBoardPanel::doPaint)
    EVT_ERASE_BACKGROUND(TBoardPanel::doErase)
    EVT_LEFT_DOWN(TBoardPanel::doLeftMouse) 
END_EVENT_TABLE()

TBoardPanel::TBoardPanel(wxWindow *parent, wxWindowID winid, const wxPoint& pos,
                         const wxSize& size, long style,const wxString& name)
    : wxPanel(parent, winid, pos, size, style, name) {        
        
    SetBackgroundStyle(wxBG_STYLE_CUSTOM);
        
    wxBitmap woodTile("IDB_BITMAPWOOD", wxBITMAP_TYPE_BMP_RESOURCE);
    int srcWidth = woodTile.GetWidth();
    int srcHeight = woodTile.GetHeight();
    
    // generate all orientations
    wxImage tileNorm = woodTile.ConvertToImage();
    wxImage tileHoriz = tileNorm.Mirror(true);
    wxImage tileVertic = tileNorm.Mirror(false);
    wxImage tileInvert = tileNorm.Mirror(true).Mirror(false);
    
    wxBitmap tileN(tileNorm);    
    wxBitmap tileH(tileHoriz);
    wxBitmap tileV(tileVertic);
    wxBitmap tileI(tileInvert);    
    
    // 2 x 2 tile
    m_tileFull.Create(srcWidth * 2, srcHeight * 2);
    wxMemoryDC dcTile;
    wxMemoryDC dcSrc;
    
    dcTile.SelectObject(m_tileFull);    
    dcSrc.SelectObject(tileN);    
    dcTile.Blit(0, 0, srcWidth, srcHeight, &dcSrc, 0, 0, wxCOPY, false);
    dcSrc.SelectObject(tileH);
    dcTile.Blit(srcWidth, 0, srcWidth, srcHeight, &dcSrc, 0, 0, wxCOPY, false);
    dcSrc.SelectObject(tileV);
    dcTile.Blit(0, srcHeight, srcWidth, srcHeight, &dcSrc, 0, 0, wxCOPY, false);
    dcSrc.SelectObject(tileI);
    dcTile.Blit(srcWidth, srcHeight, srcWidth, srcHeight, &dcSrc, 0, 0, wxCOPY, false);
    
    dcTile.SelectObject(wxNullBitmap);
    dcSrc.SelectObject(wxNullBitmap);
    
    m_cellDim = 0;    
    
    m_State = NULL;
}

void TBoardPanel::setState(GameState * state) {
    m_State = state;
}

void TBoardPanel::doPaint(wxPaintEvent& event) {
    wxBufferedPaintDC dc(this);
        
    PrepareDC(dc);        
        
    wxSize sz = GetClientSize();
    int tileW = m_tileFull.GetWidth();
    int tileH = m_tileFull.GetHeight();
            
    ::wxLogDebug("width: %d height: %d", sz.GetWidth(), sz.GetHeight());        
        
    int xc = (sz.GetWidth() / tileW) + 1;
    int yc = (sz.GetHeight() / tileH) + 1;
            
    for (int y = 0; y < yc; y++) {
        for (int x = 0; x < xc; x++) {
            dc.DrawBitmap(m_tileFull, x * tileW, y * tileH, false);             
        }
    }      
    
    if (m_State == NULL) {
        ::wxLogDebug("Paint on empty state");
        return;
    }
    
    int boardSize = m_State->board.get_boardsize();
    
    int minDim = std::min(sz.GetWidth(), sz.GetHeight());
    int cellDim = minDim / ((boardSize - 1) + 2);
    
    m_cellDim = cellDim;
    
    ::wxLogDebug("cell size: %d", cellDim);
    
    wxPen penThick(*wxBLACK, 2, wxSOLID);
    wxPen penThin(*wxBLACK, 1, wxSOLID);
    wxBrush brush(*wxBLACK, wxTRANSPARENT);
    
    // board outline
    dc.SetBrush(brush);
    dc.SetPen(penThick);
    dc.DrawRectangle(cellDim, cellDim, 
                     cellDim * (boardSize - 1), cellDim * (boardSize - 1));            

    // board lines        
    dc.SetPen(penThin);
    for (int y = 0; y < boardSize - 1; y++) {
        for (int x = 0; x < boardSize - 1; x++) {
            int xoff = cellDim + x * cellDim;
            int yoff = cellDim + y * cellDim;
            dc.DrawRectangle(xoff - 1, yoff - 1, cellDim + 1, cellDim + 1);
        }
    }    
    
    // stones
    wxBrush wbrush(*wxWHITE, wxSOLID);
    wxBrush bbrush(*wxBLACK, wxSOLID);
    int stoneSize = ((cellDim * 19)/ 40);
    
    dc.SetPen(penThin);    
    
    for (int y = 0; y < boardSize; y++) {
        for (int x = 0; x < boardSize; x++) {            
            int cell = m_State->board.get_square(x, y);
            
            if (cell == FastBoard::BLACK) {            
                dc.SetBrush(bbrush);            
            } else if (cell == FastBoard::WHITE) {                
                dc.SetBrush(wbrush);
            }
        
            if (cell != FastBoard::EMPTY) {
                int xoff = cellDim + x * cellDim;
                int yoff = cellDim + y * cellDim;
                dc.DrawCircle(xoff, yoff, stoneSize);
            }
        }
    }              
        
    dc.SetBrush(wxNullBrush);
    dc.SetPen(wxNullPen);            
}

void TBoardPanel::doErase(wxEraseEvent& event) {    
    //event.Skip();
}

void TBoardPanel::doLeftMouse(wxMouseEvent& event) {
    int startX = event.GetX();
    int startY = event.GetY();
    
    ::wxLogDebug("Left down at %d %d", startX, startY);
    
    if (m_State == NULL) {
        ::wxLogDebug("Click on empty board");
        return;
    }
    
    int boardSize = m_State->board.get_boardsize();
    
    int corrX = startX - (m_cellDim / 2);
    int corrY = startY - (m_cellDim / 2);
 
    int cellX = corrX / m_cellDim;
    int cellY = corrY / m_cellDim;
    
    if (cellX >= boardSize) cellX = boardSize - 1;
    if (cellY >= boardSize) cellY = boardSize - 1;
 
    int vtx = m_State->board.get_vertex(cellX, cellY);
    
    if (m_State->legal_move(vtx)) {
        m_State->play_move(vtx);
    }
       
    Refresh();       
    
    event.Skip();
}