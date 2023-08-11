#ifndef MYCONFIG_H
#define MYCONFIG_H

#include <QObject>
#include <QDebug>
#include <QString>
#include <QDir>
#include <QUrl>
#include <QQuickView>




class Myconfig : public QObject {

    Q_OBJECT

public:
    using QObject::QObject;

    Myconfig(QString PreviewDIR, QString PreviewFolder) noexcept;

    void setPreviewPtr(QQuickView *_ptr) noexcept;
    Q_INVOKABLE void setPreviewDIR(QString s) noexcept;
    Q_INVOKABLE void setPreviewFolder(QString s) noexcept;

    QString getPreviewDIR() noexcept;
    QString getPreviewFolder() noexcept;


public slots:
    void setPreview() const noexcept;

private:

    QString _PreviewDIRString;
    QString _PreviewFolderString;

    QQuickView *_view = nullptr;

};

#endif // MYCONFIG_H
