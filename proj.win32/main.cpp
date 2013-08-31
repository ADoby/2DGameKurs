#include "main.h"
#include "AppDelegate.h"
#include "CCEGLView.h"

USING_NS_CC;

static const float scale = 0.5f;

int APIENTRY _tWinMain(HINSTANCE hInstance,
                       HINSTANCE hPrevInstance,
                       LPTSTR    lpCmdLine,
                       int       nCmdShow)
{
    UNREFERENCED_PARAMETER(hPrevInstance);
    UNREFERENCED_PARAMETER(lpCmdLine);

    // create the application instance
    AppDelegate app;
    EGLView* eglView = EGLView::getInstance();
    eglView->setViewName("2DGame");
    eglView->setFrameSize(1920*scale, 1080*scale);
	
    return Application::getInstance()->run();
}
