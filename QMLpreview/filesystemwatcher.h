#ifndef FILE_SYSTEM_WATCHER_H
#define FILE_SYSTEM_WATCHER_H

#include <QObject>
#include <QMap>
#include <QFileSystemWatcher>
#include <QDir>
#include <QFileInfo>
#include <QDebug>
#include <QQuickView>
#include <QString>
#include <QQmlEngine>


class FileSystemWatcher : public QObject
{
    Q_OBJECT

public:
    static void addWatchPath(QString path);


    static void setPreviewPtrF(QQuickView *_ptr);
    static void setPreviewDIR(QString s);

public slots:
    void directoryUpdated(const QString &path);  // 目录更新时调用，path是监控的路径
    void fileUpdated(const QString &path);   // 文件被修改时调用，path是监控的路径

private:
    explicit FileSystemWatcher(QObject *parent = 0);

private:

    static QString _PreviewDIRStringF;
    static QString _PreviewFolderStringF;

    static QQuickView *_viewF;

    static FileSystemWatcher *m_pInstance; // 单例
    QFileSystemWatcher *m_pSystemWatcher;  // QFileSystemWatcher变量
    QMap<QString, QStringList> m_currentContentsMap; // 当前每个监控的内容目录列表

};

#endif // FILE_SYSTEM_WATCHER_H
