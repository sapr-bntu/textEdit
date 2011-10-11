#ifndef TEXTEDIT_H
#define TEXTEDIT_H

#include <QMainWindow>
#include <QMap>
#include <QPointer>
#include <QtGui>
#include <QTextEdit>
#include <QtSql/QtSql>
QT_BEGIN_NAMESPACE
class QCompleter;
QT_END_NAMESPACE
QT_BEGIN_NAMESPACE
class QAbstractItemModel;
class QComboBox;
class QCompleter;
class QLabel;
class QLineEdit;
class QProgressBar;
QT_END_NAMESPACE

QT_FORWARD_DECLARE_CLASS(QAction)
QT_FORWARD_DECLARE_CLASS(QComboBox)
QT_FORWARD_DECLARE_CLASS(QFontComboBox)
QT_FORWARD_DECLARE_CLASS(QTextEdit)
QT_FORWARD_DECLARE_CLASS(QTextCharFormat)
QT_FORWARD_DECLARE_CLASS(QMenu)
class TextEdit : public QMainWindow
{
    Q_OBJECT

public:
    TextEdit(QWidget *parent = 0);

protected:
    virtual void closeEvent(QCloseEvent *e);
     void focusInEvent(QFocusEvent *e);
     void keyPressEvent(QKeyEvent *e);


private:
    void setupFileActions();
    void setupEditActions();
    void setupTextActions();
    bool load(const QString &f);
    bool maybeSave();
    void setCurrentFileName(const QString &fileName);
    QAbstractItemModel *modelFromFile(const QString& fileName);


private slots:
    void fileNew();
    void fileOpen();
    bool fileSave();
    bool fileSaveAs();
    void filePrint();
    void filePrintPreview();
    void filePrintPdf();

    void textBold();
    void textUnderline();
    void textItalic();
    void textFamily(const QString &f);
    void textSize(const QString &p);
    void textStyle(int styleIndex);
    void textColor();
    void textAlign(QAction *a);


    void currentCharFormatChanged(const QTextCharFormat &format);
    void cursorPositionChanged();

    void clipboardDataChanged();
    void about();
    void printPreview(QPrinter *);
    void insertCompletion(const QString &completion);

private:
    void mergeFormatOnWordOrSelection(const QTextCharFormat &format);
    void fontChanged(const QFont &f);
    void colorChanged(const QColor &c);
    void alignmentChanged(Qt::Alignment a);
    QString textUnderCursor() const;


    QAction *actionSave,
        *actionTextBold,
        *actionTextUnderline,
        *actionTextItalic,
        *actionTextColor,
        *actionAlignLeft,
        *actionAlignCenter,
        *actionAlignRight,
        *actionAlignJustify,
        *actionUndo,
        *actionRedo,
        *actionCut,
        *actionCopy,
        *actionPaste;

    QComboBox *comboStyle;
    QFontComboBox *comboFont;
    QComboBox *comboSize;

    QCompleter *completer;


    QToolBar *tb;
    QString fileName;
    QTextEdit *textEdit;
};

#endif
