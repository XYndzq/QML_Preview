#include "myconfig.h"
#include "filesystemwatcher.h"

Myconfig::Myconfig(QString PreviewDIR, QString PreviewFolder) noexcept : _PreviewDIRString(qMove(PreviewDIR)), _PreviewFolderString(qMove(PreviewFolder)) {}

void Myconfig::setPreview() const noexcept{

    qDebug() << "DIR:" << _PreviewDIRString;
    qDebug() << "FILE:" << _PreviewFolderString;

    qDebug() << _view;

    if(_view != nullptr)
    {

//        _view -> setSource(QUrl("file:///C:\\Users\\XXX\\Desktop\\QMLpreview\\QMLpreview\\page1.qml"));

        _view -> setSource(QUrl(_PreviewDIRString));
        _view -> setResizeMode(QQuickView::SizeViewToRootObject);

        _view -> show();


//                FileWatcher watcher([_view, SOURCE_URL_set](){
//                    _view -> engine()->clearComponentCache();
//                    _view -> setSource(SOURCE_URL_set);
//                });

//                watcher.setDirectory(DIRECTORY_set.absolutePath());

    }

}


void Myconfig::setPreviewPtr(QQuickView *_ptr) noexcept {

    _view = _ptr;
    FileSystemWatcher::setPreviewPtrF(_view);
}

void Myconfig::setPreviewDIR(QString s) noexcept {

    _PreviewDIRString = s;
    FileSystemWatcher::addWatchPath(getPreviewDIR().mid(8));
    FileSystemWatcher::setPreviewDIR(s);

}

void Myconfig::setPreviewFolder(QString s) noexcept {

    _PreviewFolderString = s;

}

QString Myconfig::getPreviewDIR() noexcept {
    return _PreviewDIRString;
}


QString Myconfig::getPreviewFolder() noexcept {
    return _PreviewFolderString;


}



