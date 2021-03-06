//-----------------------------------------------------------
// 
// UDKinectPreviewWindow.h
//
// Copyright (c) 2012 UDKinect, Charlie Hodara
//
// This file is released under the MIT License.
//
// Permission is hereby granted, free of charge, to any person obtaining 
// a copy of this software and associated documentation files (the "Software"), 
// to deal in the Software without restriction, including without limitation 
// the rights to use, copy, modify, merge, publish, distribute, sublicense, 
// and/or sell copies of the Software, and to permit persons to whom the 
// Software is furnished to do so, subject to the following conditions: 
// The above copyright notice and this permission notice shall be 
// included in all copies or substantial portions of the Software.
//
// THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, 
// EXPRESS OR IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES 
// OF MERCHANTABILITY, FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. 
// IN NO EVENT SHALL THE AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR 
// ANY CLAIM, DAMAGES OR OTHER LIABILITY, WHETHER IN AN ACTION OF 
// CONTRACT, TORT OR OTHERWISE, ARISING FROM, OUT OF OR IN CONNECTION 
// WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE SOFTWARE. 
//
//-----------------------------------------------------------

#ifndef __UDKINECT_PREVIEW_WINDOW_H__
#define __UDKINECT_PREVIEW_WINDOW_H__

#include "UDKInectFundamental.h"

namespace UDKinect
{
	class PreviewWindow
	{
	public: 
		PreviewWindow();
		~PreviewWindow();

		void show();
		void hide();

		void setSkeletonVisible( bool bVisible ) { m_bSkeletonVisible = bVisible; }

		HWND getHwnd() const { return m_Hwnd; }

		void setFrameBuffer( int width, int height, RGBQUAD* pImageBuffer );

		static LRESULT CALLBACK	staticWinProc( HWND hWnd, UINT msg, WPARAM wParam, LPARAM lParam );
		LRESULT CALLBACK		winProc( HWND hWnd, UINT msg, WPARAM wParam, LPARAM lParam );
		void					processMessages();

	private:
		HWND	m_Hwnd;

		bool	m_bVisible;

		bool	m_bSkeletonVisible;

		int		m_Width;
		int		m_Height;		

		void createWindow();

		void displaySkeleton( HDC hdc, const NUI_SKELETON_DATA* pSkel, COLORREF color );
		void drawSkeletonSegment( HDC hdc, POINT* points, const NUI_SKELETON_DATA* pSkel, int numJoints, ... );
	};
} // namespace UDKinect

#endif // __UDKINECT_PREVIEW_WINDOW_H__