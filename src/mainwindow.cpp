#include "mainwindow.h"

#include <QtGui/QFileDialog>
#include <QSettings>
#include <QFile>
#include <QApplication>
#include <QVariant>
#include <QImage>
#include <QPixmap>
#include <QTextStream>
#include <QWhatsThis>
#include <QMessageBox>
#include <QUrl>

#include "createtableform.h"
#include "createindexform.h"
#include "deletetableform.h"
#include "deleteindexform.h"
#include "aboutform.h"
#include "choosetableform.h"
#include "edittableform.h"
#include "editfieldform.h"
#include "importcsvform.h"
#include "exporttablecsvform.h"
#include "preferencesform.h"
#include "editform.h"
#include "findform.h"

void Ui_mainForm::retranslateUi(QMainWindow *mainForm)
{
    mainForm->setWindowTitle(QObject::tr("Browser"));

    fileNewAction->setIconText(QObject::tr("New Database"));
    fileNewAction->setText(QObject::tr("&New Database"));
    fileNewAction->setToolTip(QObject::tr("Create a new database file"));
    fileNewAction->setWhatsThis(QObject::tr("This option is used to create a new database file."));
    fileNewAction->setShortcut(QObject::tr("Ctrl+N"));

    fileOpenAction->setIconText(QObject::tr("Open Database"));
    fileOpenAction->setText(QObject::tr("&Open Database"));
    fileOpenAction->setToolTip(QObject::tr("Open an existing database file"));
    fileOpenAction->setWhatsThis(QObject::tr("This option is used to open an existing database file."));
    fileOpenAction->setShortcut(QObject::tr("Ctrl+O"));

    fileExitAction->setIconText(QObject::tr("Exit"));
    fileExitAction->setText(QObject::tr("E&xit"));
    fileExitAction->setShortcut(QString());

    editCopyAction->setIconText(QObject::tr("Copy"));
    editCopyAction->setText(QObject::tr("&Copy"));
    editCopyAction->setWhatsThis(QObject::tr("Copies the selected text to the clipboard"));
    editCopyAction->setShortcut(QObject::tr("Ctrl+C"));

    editPasteAction->setIconText(QObject::tr("Paste"));
    editPasteAction->setText(QObject::tr("&Paste"));
    editPasteAction->setWhatsThis(QObject::tr("Pastes text from the clipboard into the current text insertion point"));
    editPasteAction->setShortcut(QObject::tr("Ctrl+V"));

    editFindAction->setIconText(QObject::tr("Find"));
    editFindAction->setText(QObject::tr("&Find..."));
    editFindAction->setShortcut(QObject::tr("F"));

    helpContentsAction->setIconText(QObject::tr("Contents"));
    helpContentsAction->setText(QObject::tr("&Contents..."));
    helpContentsAction->setShortcut(QString());

    helpIndexAction->setIconText(QObject::tr("Index"));
    helpIndexAction->setText(QObject::tr("&Index..."));
    helpIndexAction->setShortcut(QString());

    helpAboutAction->setIconText(QObject::tr("About"));
    helpAboutAction->setText(QObject::tr("&About"));
    helpAboutAction->setShortcut(QString());

    fileCloseAction->setIconText(QObject::tr("Close Database"));
    fileCloseAction->setText(QObject::tr("Close Database"));

    newRecordAction->setIconText(QObject::tr("New Record"));
    newRecordAction->setText(QObject::tr("New Record"));

    fileCompactAction->setIconText(QObject::tr("Compact Database"));
    fileCompactAction->setText(QObject::tr("Compact Database"));
    fileCompactAction->setStatusTip(QObject::tr("Compact the database file, removing space wasted by deleted records."));
    fileCompactAction->setWhatsThis(QObject::tr("Compact the database file, removing space wasted by deleted records."));

    helpWhatsThisAction->setIconText(QObject::tr("What's This?"));
    helpWhatsThisAction->setText(QObject::tr("What's This?"));
    helpWhatsThisAction->setShortcut(QObject::tr("Shift+F1"));

    sqlLogAction->setIconText(QObject::tr("SQL Log"));
    sqlLogAction->setText(QObject::tr("SQL Log"));
    sqlLogAction->setWhatsThis(QObject::tr("Display or hide the SQL log window, which stores all SQL commands issued by the user or the application."));

    fileImportCSVAction->setIconText(QObject::tr("Table from CSV file"));
    fileImportCSVAction->setText(QObject::tr("Table from CSV file"));
    fileImportCSVAction->setToolTip(QObject::tr("Open a wizard that lets you import data from a comma separated text file into a database table."));
    fileImportCSVAction->setWhatsThis(QObject::tr("Open a wizard that lets you import data from a comma separated text file into a database table. CSV files can be created on most database and spreadsheet applications."));

    fileExportCSVAction->setIconText(QObject::tr("Table as CSV file"));
    fileExportCSVAction->setText(QObject::tr("Table as CSV file"));
    fileExportCSVAction->setToolTip(QObject::tr("Export a database table as a comma separated text file."));
    fileExportCSVAction->setWhatsThis(QObject::tr("Export a database table as a comma separated text file, ready to be imported into other database or spreadsheet applications."));

    fileSaveAction->setIconText(QObject::tr("Write Changes"));
    fileSaveAction->setText(QObject::tr("Revert Changes"));
    fileSaveAction->setToolTip(QObject::tr("Write changes to the database file"));
    fileSaveAction->setWhatsThis(QObject::tr("This option is used to save changes to the database file."));

    fileRevertAction->setIconText(QObject::tr("Revert Changes"));
    fileRevertAction->setText(QObject::tr("Revert Changes"));
    fileRevertAction->setToolTip(QObject::tr("Revert database to last saved state"));
    fileRevertAction->setWhatsThis(QObject::tr("This option is used to revert the current database file to its last saved state. All changes made since the last save operation are lost."));

    //fileImportAction->setIconText(QObject::tr("Import"));
    //fileImportAction->setText(QObject::tr("Import"));
    //fileExportAction->setIconText(QObject::tr("Export"));
    //fileExportAction->setText(QObject::tr("Export"));

    editCreateTableAction->setIconText(QObject::tr("Create Table"));
    editCreateTableAction->setText(QObject::tr("Create Table"));
    editCreateTableAction->setWhatsThis(QObject::tr("Open the Create Table wizard, where it is possible to define the name and fields for a new table in the database"));

    editDeleteTableAction->setIconText(QObject::tr("Delete Table"));
    editDeleteTableAction->setText(QObject::tr("Delete Table"));

    editDeleteTableActionPopup->setIconText(QObject::tr("Delete Table"));
    editDeleteTableActionPopup->setText(QObject::tr("Delete Table"));


    editDeleteTableAction->setWhatsThis(QObject::tr("Open the Delete Table wizard, where you can select a database table to be dropped."));

    editModifyTableAction->setIconText(QObject::tr("Modify Table"));
    editModifyTableAction->setText(QObject::tr("Modify Table"));

    editModifyTableActionPopup->setIconText(QObject::tr("Modify Table"));
    editModifyTableActionPopup->setText(QObject::tr("Modify Table"));

    editModifyTableAction->setWhatsThis(QObject::tr("Open the Modify Table wizard, where it is possible to rename an existing table. It is also possible to add or delete fields form a table, as well as modify field names and types."));

    editCreateIndexAction->setIconText(QObject::tr("Create Index"));
    editCreateIndexAction->setText(QObject::tr("Create Index"));
    editCreateIndexAction->setWhatsThis(QObject::tr("Open the Create Index wizard, where it is possible to define a new index on an existing database table."));

    editDeleteIndexAction->setIconText(QObject::tr("Delete Index"));
    editDeleteIndexAction->setText(QObject::tr("Delete Index"));
    editDeleteIndexAction->setWhatsThis(QObject::tr("Open the Delete Index wizard, where you can select a database index to be dropped."));

    fileImportSQLAction->setIconText(QObject::tr("Database from SQL file"));
    fileImportSQLAction->setText(QObject::tr("Database from SQL file"));
    fileImportSQLAction->setToolTip(QObject::tr("Import data from an .sql dump text file into a new or existing database."));
    fileImportSQLAction->setWhatsThis(QObject::tr("This option lets you import data from an .sql dump text file into a new or existing database. SQL dump files can be created on most database engines, including MySQL and PostgreSQL."));

    fileExportSQLAction->setIconText(QObject::tr("Database to SQL file"));
    fileExportSQLAction->setText(QObject::tr("Database to SQL file"));
    fileExportSQLAction->setToolTip(QObject::tr("Export a database to a .sql dump text file."));
    fileExportSQLAction->setWhatsThis(QObject::tr("This option lets you export a database to a .sql dump text file. SQL dump files contain all data necessary to recreate the database on most database engines, including MySQL and PostgreSQL."));

    editPreferencesAction->setIconText(QObject::tr("Preferences"));
    editPreferencesAction->setText(QObject::tr("Preferences"));
    editPreferencesAction->setToolTip(QObject::tr("Open the preferences window.."));
    editPreferencesAction->setWhatsThis(QObject::tr("Open the preferences window."));

    mainTab->setProperty("toolTip", QVariant(QString()));
    mainTab->setTabText(mainTab->indexOf(structure), QObject::tr("Database Structure"));

    textLabel1->setText(QObject::tr("Table:"));

    comboBrowseTable->clear();
    comboBrowseTable->insertItems(0, QStringList()
        << QObject::tr("select")
        << QObject::tr("users")
    );
    comboBrowseTable->setProperty("toolTip", QVariant(QObject::tr("Select a table to browse data")));
    comboBrowseTable->setProperty("whatsThis", QVariant(QObject::tr("Use this list to select a table to be displayed in the database view")));

    buttonFind->setText(QString());
    buttonFind->setProperty("toolTip", QVariant(QObject::tr("Open or close the floating find window")));
    buttonFind->setProperty("whatsThis", QVariant(QObject::tr("This button toggles the appearance of the Find window, used to search records in the database view")));


    buttonRefresh->setProperty("toolTip", QVariant( QObject::tr("Refresh the data in the selected table.")));
    buttonRefresh->setProperty("whatsThis", QVariant( QObject::tr("This button refreshes the data in the currently selected table.")));

    buttonNewRecord->setText(QObject::tr("New Record"));
    buttonNewRecord->setProperty("toolTip", QVariant(QObject::tr("Insert a new record in the current table")));
    buttonNewRecord->setProperty("whatsThis", QVariant(QObject::tr("This button creates a new, empty record in the database")));

    buttonDeleteRecord->setText(QObject::tr("Delete Record"));
    buttonDeleteRecord->setProperty("toolTip", QVariant(QObject::tr("Delete the current record")));
    buttonDeleteRecord->setProperty("whatsThis", QVariant(QObject::tr("This button deletes the record currently selected in the database")));


    dataTable->setProperty("toolTip", QVariant(QString()));
    dataTable->setProperty("whatsThis", QVariant(QObject::tr("This is the database view. You can double-click any record to edit its contents in the cell editor window.")));

    buttonPrevious->setText(QObject::tr("<"));
    buttonPrevious->setProperty("toolTip", QVariant(QObject::tr("Go to previous record set page")));
    buttonPrevious->setProperty("whatsThis", QVariant(QObject::tr("This button is used to navigate to the previous set of 1000 records in the database view")));

    labelRecordset->setText(QObject::tr("1000 - 2000 of 100000"));

    buttonNext->setText(QObject::tr(">"));
    buttonNext->setProperty("toolTip", QVariant(QObject::tr("Go to next record set page")));
    buttonNext->setProperty("whatsThis", QVariant(QObject::tr("This button is used to navigate to the next 1000 records set in the database view")));

    buttonGoto->setText(QObject::tr("Go to:"));
    buttonGoto->setProperty("toolTip", QVariant(QObject::tr("Click here to browse the specified record ")));
    buttonGoto->setProperty("whatsThis", QVariant(QObject::tr("This button is used to navigate to the record number specied in the Go to: area.")));

    editGoto->setText(QObject::tr("0"));
    editGoto->setProperty("toolTip", QVariant(QObject::tr("Enter record number to browse")));
    editGoto->setProperty("whatsThis", QVariant(QObject::tr("Type a record number in this area and click the Go to: button to display the record in the database view")));

    mainTab->setTabText(mainTab->indexOf(browser), QObject::tr("Browse Data"));
    textLabel1_2->setText(QObject::tr("SQL string:"));

    sqlTextEdit->setProperty("toolTip", QVariant(QObject::tr("Type SQL string here")));
    sqlTextEdit->setProperty("whatsThis", QVariant(QObject::tr("Type the SQL query in this area, and press the button below to execute it. Results and error messages will be shown in the fields at the bottom of this form.")));

    executeQueryButton->setText(QObject::tr("Execute query"));
    executeQueryButton->setProperty("toolTip", QVariant(QObject::tr("Execute SQL query")));
    executeQueryButton->setProperty("whatsThis", QVariant(QObject::tr("This button is used to execute the SQL query entered in the text area above.")));

    textLabel2->setText(QObject::tr("Error message from database engine:"));

    queryErrorLineEdit->setProperty("toolTip", QVariant(QObject::tr("Error messages")));
    queryErrorLineEdit->setProperty("whatsThis", QVariant(QObject::tr("Messages returned from the database engine when the SQL query is executed are displayed in this area.")));

    textLabel3->setText(QObject::tr("Data returned:"));

    queryResultTableView->setProperty("toolTip", QVariant(QObject::tr("Query generated data")));
    queryResultTableView->setProperty("whatsThis", QVariant(QObject::tr("This table displays data returned from the database engine as a result of the SQL query. You can not modify data directly on this view, only consult it.")));

    mainTab->setTabText(mainTab->indexOf(query), QObject::tr("Execute SQL"));
    //Toolbar->setLabel(QObject::tr("Toolbar"));
    fileMenu->setTitle(QObject::tr("&File"));
    importMenu->setTitle(QObject::tr("Import"));
    exportMenu->setTitle(QObject::tr("Export"));
    EditMenu->setTitle(QObject::tr("Edit"));
    ViewMenu->setTitle(QObject::tr("View"));
    PopupMenu->setTitle(QObject::tr("Help"));
} // retranslateUi

/*
 *  Constructs a mainForm as a child of 'parent', with the
 *  name 'name' and widget flags set to 'f'.
 *
 */
mainForm::mainForm(QWidget* parent)
    : QMainWindow(parent)
{
    setupUi(this);
    setAcceptDrops(true);

    (void)statusBar();
    init();
}

/*
 *  Destroys the object and frees any allocated resources
 */
mainForm::~mainForm()
{
    destroy();
    // no need to delete child widgets, Qt does it all for us
}

/*
 *  Sets the strings of the subwidgets using the current
 *  language.
 */
void mainForm::languageChange()
{
    retranslateUi(this);
}

void mainForm::init()
{
    
    findWin = 0;
    editWin = 0;

    clipboard = QApplication::clipboard();

    recsPerView = 1000;
    recAtTop = 0;
    gotoValidator = new QIntValidator(0, 0, this);
    editGoto->setValidator(gotoValidator);
    gotoValidator->setRange ( 0, 0);
    resetBrowser();
    this->setWindowTitle(QApplication::applicationName());
    this->setWindowIcon( QPixmap( g_applicationIconName ) );
    buttonNext->setEnabled(false);
    buttonPrevious->setEnabled(false);
    updateRecentFileActions();


    if(!editWin){
        editWin = new editForm(this);
        connect( editWin, SIGNAL( goingAway() ),
                 this,    SLOT( editWinAway() ) );
        connect( editWin, SIGNAL( updateRecordText(int, int , QString) ),
                 this,      SLOT( updateRecordText(int, int , QString) ) );
    }

    connect( logWin, SIGNAL( goingAway() ),  this, SLOT( logWinAway() ) );
    connect( logWin, SIGNAL( dbState(bool) ),this, SLOT( dbState(bool)  ) );

    updatePreferences();

    //connect db and log
    db.logWin = logWin;

}

void mainForm::destroy()
{
    if (gotoValidator){
        delete gotoValidator;
    }
}

//***********************************************************
//*** Open File
void mainForm::fileOpen(const QString & fileName)
{
    QString wFile = fileName;
    if (!QFile::exists(wFile))
    {
        wFile = QFileDialog::getOpenFileName(
                    this,
                    "Choose a database file",
                    defaultlocation);
    }
    if (QFile::exists(wFile) )
    {
        if (db.open(wFile))
        {
            this->setWindowTitle(QApplication::applicationName() +" - "+wFile);
            fileCloseAction->setEnabled(true);
            fileCompactAction->setEnabled(true);
            editCreateTableAction->setEnabled(true);
            editDeleteTableAction->setEnabled(true);
            editModifyTableAction->setEnabled(true);
            editCreateIndexAction->setEnabled(true);
            editDeleteIndexAction->setEnabled(true);
            setCurrentFile(wFile);
        } else {
            QString err = "An error occurred:  ";
            err.append(db.lastErrorMessage);
            QMessageBox::information( this, QApplication::applicationName() ,err);
        }
        populateStructure();
        resetBrowser();
    }
}


void mainForm::fileOpen()
{
    fileOpen(QString());
}



void mainForm::fileNew()
{
    QString fileName = QFileDialog::getSaveFileName(
                this,
                "Choose a filename to save under",
                defaultlocation);
    if (QFile::exists(fileName) )
    {
        QString err = "File ";
        err.append(fileName);
        err.append(" already exists. Please choose a different name");
        QMessageBox::information( this, QApplication::applicationName() ,err);
        return;
    }
    if (!fileName.isNull())
    {
        db.create(fileName);
        this->setWindowTitle( QApplication::applicationName() +" - "+fileName);
        populateStructure();
        resetBrowser();
        createTable();
        fileCloseAction->setEnabled(true);
        fileCompactAction->setEnabled(true);
        editCreateTableAction->setEnabled(true);
        editDeleteTableAction->setEnabled(true);
        editModifyTableAction->setEnabled(true);
        editCreateIndexAction->setEnabled(true);
        editDeleteIndexAction->setEnabled(true);
        setCurrentFile(fileName);
    }
}

//** Populate DbTree Structure
void mainForm::populateStructure()
{
    dbTreeWidget->model()->removeRows(0, dbTreeWidget->model()->rowCount());
    if (!db.isOpen()){
        return;
    }
    db.updateSchema();
    tableMap::Iterator it;
    tableMap tmap = db.tbmap;

    for ( it = tmap.begin(); it != tmap.end(); ++it ) {

        //* Table node
        QTreeWidgetItem *tableItem = new QTreeWidgetItem();
        tableItem->setText(0, it.value().getname());
        tableItem->setText(1,  "table");
        tableItem->setText(3, it.value().getsql());
        tableItem->setIcon(0, QIcon(":/icons/table"));
        dbTreeWidget->addTopLevelItem(tableItem);

        //* Field Nodes
        fieldMap::Iterator fit;
        fieldMap fmap = it.value().fldmap;
        for ( fit = fmap.begin(); fit != fmap.end(); ++fit ) {
            QTreeWidgetItem *fldItem = new QTreeWidgetItem(tableItem);
            fldItem->setText( 0, fit.value().getname() );
            fldItem->setText( 1, "field"  );
            fldItem->setText( 2, fit.value().gettype() );
            fldItem->setIcon(0, QIcon(":/icons/field"));
        }
        // TODO make an options/setting autoexpand
        dbTreeWidget->setItemExpanded(tableItem, true);
    }
    indexMap::Iterator it2;
    indexMap imap = db.idxmap;
    for ( it2 = imap.begin(); it2 != imap.end(); ++it2 ) {
        QTreeWidgetItem *idxItem = new QTreeWidgetItem();
        idxItem->setText( 0, it2.value().getname() );
        idxItem->setText( 1, "index"  );
        idxItem->setText( 3, it2.value().getsql() );
        idxItem->setIcon(0, QIcon(":/icons/index"));
        dbTreeWidget->addTopLevelItem(idxItem);
    }
}

void mainForm::populateTable( const QString & tablename)
{
    bool mustreset = false;
    QApplication::setOverrideCursor( Qt::WaitCursor );
    if (tablename.compare(db.curBrowseTableName)!=0)
        mustreset = true;

    if (!db.browseTable(tablename)){
        dataTable->setRowCount( 0 );
        dataTable->setColumnCount( 0 );
        QApplication::restoreOverrideCursor();
        if (findWin){
            findWin->resetFields(db.getTableFields(""));
            findWin->resetResults();
        }
        return;
    }

    if (mustreset){
        recAtTop = 0;
        updateTableView(0);
        if (findWin) findWin->resetFields(db.getTableFields(db.curBrowseTableName));
    } else {
        updateTableView(-1);
    }
    //got to keep findWin in synch
    if (findWin){
        findWin->resetResults();
    }
    if (editWin)
    {
        editWin->reset();
    }
    QApplication::restoreOverrideCursor();
}

void mainForm::resetBrowser()
{
    recAtTop = 0;
    QString sCurrentTable = comboBrowseTable->currentText();
    comboBrowseTable->clear();
    QStringList tab = db.getTableNames();
    if  (tab.isEmpty()){
        comboBrowseTable->addItem("");
    } else {
        comboBrowseTable->addItems(tab);
    }
    setRecordsetLabel();
    int pos = comboBrowseTable->findText(sCurrentTable);
    pos = pos == -1 ? 0 : pos;
    comboBrowseTable->setCurrentIndex(pos);
    populateTable(comboBrowseTable->currentText());
}

void mainForm::fileClose()
{
    db.close();
    this->setWindowTitle(QApplication::applicationName());
    resetBrowser();
    populateStructure();
    fileCloseAction->setEnabled(false);
    fileCompactAction->setEnabled(false);
    editCreateTableAction->setEnabled(false);
    editDeleteTableAction->setEnabled(false);
    editModifyTableAction->setEnabled(false);
    editCreateIndexAction->setEnabled(false);
    editDeleteIndexAction->setEnabled(false);
}


void mainForm::fileExit()
{
    if (db.isOpen())
    {
        if (db.getDirty())
        {
            QString msg = "Do you want to save the changes made to the database file ";
            msg.append(db.curDBFilename);
            msg.append("?");
            if (QMessageBox::question( this, QApplication::applicationName() ,msg, QMessageBox::Yes, QMessageBox::No)==QMessageBox::Yes)
            {
                db.save();
            } else {
                //not really necessary, I think... but will not hurt.
                db.revert();
            }
        }
        db.close();
    }
    QApplication::exit( 0 );
}

void mainForm::closeEvent( QCloseEvent * )
{
    fileExit();
}

void mainForm::addRecord()
{
    if (db.addRecord()){
        populateTable(db.curBrowseTableName);
        //added record will be the last one in view
        recAtTop = ((db.getRecordCount()-1)/recsPerView)*recsPerView;
        updateTableView(db.getRecordCount()-recAtTop-1);
    }else{
        QMessageBox::information( this, QApplication::applicationName(),
                                  "Error adding record, make sure a table is selected.\n\n"
                                  "If the table contain fields declared as NOT NULL\n"
                                  "please select EDIT->PREFERENCES and adjust the\n"
                                  "default value for new records to insert an empty string." );
    }
}


void mainForm::deleteRecord()
{
    if (dataTable->currentRow()!=-1){
        int lastselected = dataTable->currentRow();
        db.deleteRecord(dataTable->currentRow()+recAtTop);
        populateTable(db.curBrowseTableName);
        int nextselected = lastselected ;
        if (nextselected > db.getRecordCount()){
            nextselected = db.getRecordCount();
        }
        if (nextselected>0){
            selectTableLine(nextselected);
        }
    } else {
        QMessageBox::information( this, QApplication::applicationName(), "Please select a record first" );
    }
}

void mainForm::updateTableView(int lineToSelect)
{
    //  qDebug("line to select value is %d, rowAttop = %d",lineToSelect, recAtTop);
    QApplication::setOverrideCursor( Qt::WaitCursor );

    dataTable->setRowCount(0);
    dataTable->setColumnCount( db.browseFields.count() );
    dataTable->setHorizontalHeaderLabels(db.browseFields);

    rowList tab = db.browseRecs;
    int maxRecs = db.getRecordCount();
    int recsThisView = maxRecs - recAtTop;

    if (recsThisView>recsPerView)
        recsThisView = recsPerView;

    // qDebug("recsthisview= %d\n",recsThisView);

    dataTable->setRowCount(recsThisView);

    if ( recsThisView > 0 ) {

        int rowNum = 0;
        int colNum = 0;
        //int dcols =0;
        QString rowLabel;
        for (int i = recAtTop; i < tab.size(); ++i)
            //for ( int  = tab.at(recAtTop); rt !=tab.end(); ++rt )
        {
            rowLabel.setNum(recAtTop+rowNum+1);
            dataTable->setVerticalHeaderItem(rowNum, new QTableWidgetItem( rowLabel ));
            colNum = 0;
            QStringList& rt = tab[i];
            for (int e = 1; e < rt.size(); ++e)
                //for ( QStringList::Iterator it = (*rt).begin(); it != (*rt).end(); ++it )
            {
                //skip first one (the rowid)
                //  if (it!=(*rt).begin()){
                QString& content = rt[e];
                QString firstline = content.section( '\n', 0,0 );
                if (content.length()>MAX_DISPLAY_LENGTH)
                {
                    firstline.truncate(MAX_DISPLAY_LENGTH);
                    firstline.append("...");
                }
                QTableWidgetItem* item = new QTableWidgetItem(firstline);
                item->setFlags(Qt::ItemIsSelectable | Qt::ItemIsEnabled);
                dataTable->setItem( rowNum, colNum, item);
                colNum++;
                //}
            }
            rowNum++;
            if (rowNum==recsThisView) break;
        }

    }
    //dataTable->clearSelection(true);
    if (lineToSelect!=-1){
        //qDebug("inside selection");
        selectTableLine(lineToSelect);
    }
    setRecordsetLabel();
    QApplication::restoreOverrideCursor();
}

void mainForm::selectTableLine(int lineToSelect)
{
    dataTable->clearSelection();
    dataTable->selectRow(lineToSelect);
    dataTable->setCurrentCell(lineToSelect, 0);
    dataTable->scrollToItem(dataTable->itemAt(lineToSelect, 0));
}

void mainForm::navigatePrevious()
{
    int nextFirstRec = recAtTop - recsPerView;
    if (nextFirstRec  >= 0 ) {
        recAtTop = nextFirstRec;
        updateTableView(-1);
    }
}


void mainForm::navigateNext()
{
    int nextFirstRec = recAtTop + recsPerView;
    //qDebug("called navigatenext, nextFirstRec=%d\n",nextFirstRec);
    if (nextFirstRec < db.getRecordCount() ) {
        recAtTop = nextFirstRec;
        updateTableView(-1);
    }
}


void mainForm::navigateGoto()
{
    QString typed = editGoto->text();
    bool ok;
    int dec = typed.toInt( &ok);
    if (dec==0) dec=1;
    if (dec>db.getRecordCount()) dec = db.getRecordCount();

    recAtTop = ((dec-1)/recsPerView)*recsPerView;
    updateTableView(dec-recAtTop-1);
    editGoto->setText(QString::number(dec,10));
}

void mainForm::setRecordsetLabel()
{
    if (db.getRecordCount()==0){
        labelRecordset->setText("0 - 0 of 0");
    } else {
        QString label = QString::number(recAtTop+1,10);
        label.append(" - ");
        int lastrec = db.getRecordCount();
        int lastthisview = recAtTop+recsPerView;
        if (lastthisview > lastrec) lastthisview = lastrec;
        label.append(QString::number(lastthisview,10));
        label.append(" of ");
        label.append(QString::number(db.getRecordCount(),10));
        labelRecordset->setText(label);
    }
    gotoValidator->setRange ( 0, db.getRecordCount());

    if (db.getRecordCount()>1000){
        if (recAtTop>=1000) {
            buttonPrevious->setEnabled(TRUE);
        } else {
            buttonPrevious->setEnabled(FALSE);
        }
        if (db.getRecordCount()>=(recAtTop+1000)) {
            buttonNext->setEnabled(TRUE);
        } else {
            buttonNext->setEnabled(FALSE);
        }
    } else {
        buttonNext->setEnabled(FALSE);
        buttonPrevious->setEnabled(FALSE);
    }
}

void mainForm::browseFind(bool open)
{
    if (open){
        if ( ! findWin ) {
            findWin= new findForm( this );
            connect( findWin, SIGNAL( lookfor(const QString&, const QString&, const QString&) ),
                     this, SLOT( lookfor(const QString&, const QString&, const QString&) ) );
            connect( findWin, SIGNAL( showrecord(int) ),this, SLOT( showrecord(int) ) );
            connect( findWin, SIGNAL( goingAway() ),this, SLOT( browseFindAway() ) );
        }
        findWin->resetFields(db.getTableFields(db.curBrowseTableName));
        findWin->show();
    } else {
        if (findWin){
            findWin->hide();
        }
    }
}

void mainForm::browseFindAway()
{
    buttonFind->toggle();
}

void mainForm::browseRefresh()
{
    populateTable(comboBrowseTable->currentText());
}

void mainForm::lookfor( const QString & wfield, const QString & woperator, const QString & wsearchterm )
{
    if (!db.isOpen()){
        QMessageBox::information( this, QApplication::applicationName(), "There is no database opened. Please open or create a new database file." );
        return;
    }
    
    //we may need to modify woperator and wsearchterm, so use copies
    QString finaloperator = woperator;
    QString finalsearchterm = wsearchterm;
    
    //special case for CONTAINS operator: use LIKE and surround the search word with % characters
    if (woperator.compare("contains")==0){
        finaloperator = QString("LIKE");
        QString newsearchterm = "%";
        newsearchterm.append(wsearchterm);
        newsearchterm.append("%");
        finalsearchterm = QString(newsearchterm);
    }
    QApplication::setOverrideCursor( Qt::WaitCursor );
    QString statement = "SELECT rowid, ";
    statement.append(wfield);
    statement.append("  FROM ");
    statement.append(db.curBrowseTableName);
    statement.append(" WHERE ");
    statement.append(wfield);
    statement.append(" ");
    statement.append(finaloperator);
    statement.append(" ");
    //searchterm needs to be quoted if it is not a number
    bool ok = false;
    wsearchterm.toDouble(&ok);
    if (!ok) wsearchterm.toInt(&ok, 10);
    if (!ok) {//not a number, quote it
        char * formSQL = sqlite3_mprintf("%Q",(const char *) finalsearchterm.toUtf8());
        statement.append(formSQL);
        if (formSQL) sqlite3_free(formSQL);
    } else {//append the number, unquoted
        statement.append(finalsearchterm);
    }
    statement.append(" ORDER BY rowid; ");
    resultMap res = db.getFindResults(statement);
    findWin->showResults(res);
    QApplication::restoreOverrideCursor();
}


void mainForm::showrecord( int dec )
{
    recAtTop = ((dec-1)/recsPerView)*recsPerView;
    updateTableView(dec-recAtTop-1);
}

void mainForm::createTable()
{
    if (!db.isOpen()){
        QMessageBox::information( this, QApplication::applicationName(), "There is no database opened. Please open or create a new database file." );
        return;
    }
    createTableForm * tableForm = new createTableForm( this );
    tableForm->setModal(true);
    if ( tableForm->exec() ) {
        if (!db.executeSQL(tableForm->createStatement)){
            QString error = "Error: could not create the table. Message from database engine:  ";
            error.append(db.lastErrorMessage);
            QMessageBox::warning( this, QApplication::applicationName(), error );
        } else {
            populateStructure();
            resetBrowser();
        }
    }
}


void mainForm::createIndex()
{
    if (!db.isOpen()){
        QMessageBox::information( this, QApplication::applicationName(), "There is no database opened. Please open or create a new database file." );
        return;
    }
    createIndexForm * indexForm = new createIndexForm( this );
    indexForm->setModal(true);
    tableMap tmap = db.tbmap;
    indexForm->populateTable( tmap );
    if ( indexForm->exec() ) {
        if (!db.executeSQL(indexForm->createStatement)){
            QString error = "Error: could not create the index. Message from database engine:  ";
            error.append(db.lastErrorMessage);
            QMessageBox::warning( this, QApplication::applicationName(), error );
        } else {
            populateStructure();
            resetBrowser();
        }
    }
}


void mainForm::compact()
{
    QApplication::setOverrideCursor( Qt::WaitCursor );
    if (db.isOpen()){
        if (!db.compact()){
            QString error = "Error: could not compact the database file. Message from database engine:  ";
            error.append(db.lastErrorMessage);
            QMessageBox::warning( this, QApplication::applicationName(), error );
        } else {
            QMessageBox::warning( this, QApplication::applicationName(), "Database compacted" );
        }
    }
    db.open(db.curDBFilename);
    populateStructure();
    resetBrowser();
    fileCloseAction->setEnabled(true);
    fileCompactAction->setEnabled(true);
    QApplication::restoreOverrideCursor( );
}


void mainForm::deleteTable()
{
    if (!db.isOpen()){
        QMessageBox::information( this, QApplication::applicationName(), "There is no database opened." );
        return;
    }
    deleteTableForm * tableForm = new deleteTableForm( this );
    tableForm->setModal(true);
    tableForm->populateOptions( db.getTableNames());
    if ( tableForm->exec() ) {
        QString statement = "DROP TABLE ";
        statement.append(tableForm->option);
        statement.append(";");
        if (!db.executeSQL( statement)){
            QString error = "Error: could not delete the table. Message from database engine:  ";
            error.append(db.lastErrorMessage);
            QMessageBox::warning( this, QApplication::applicationName(), error );
        } else {
            populateStructure();
            resetBrowser();
        }
    }
}

//*****************************************
//** Edit Table
void mainForm::editTable()
{
    if (!db.isOpen()){
        QMessageBox::information( this, QApplication::applicationName(), "There is no database opened." );
        return;
    }
    chooseTableForm * tableForm = new chooseTableForm( this );
    tableForm->setModal(true);
    QStringList tablelist = db.getTableNames();
    if (tablelist.empty()){
        QMessageBox::information( this, QApplication::applicationName(), "There are no tables to edit in this database." );
        return;
    }
    tableForm->populateOptions( tablelist );
    if ( tableForm->exec() ) {
        //statement.append(tableForm->option);
        editTableForm * edTableForm = new editTableForm( this );
        edTableForm->setModal(true);
        //send table name ? or handle it all from here?
        edTableForm->setActiveTable(&db, tableForm->option);
        edTableForm->exec();
        //check modified status
        if (edTableForm->modified)
        {
            populateStructure();
            resetBrowser();
        }
    }
}
void mainForm::editTablePopup()
{
    if (!db.isOpen()){
        QMessageBox::information( this, QApplication::applicationName(), "There is no database opened." );
        return;
    }
    if(!dbTreeWidget->selectionModel()->hasSelection()){
        return;
    }
    QString tableToEdit =dbTreeWidget->currentItem()->text(0);
    qDebug(tableToEdit.toUtf8());
    //chooseTableForm * tableForm = new chooseTableForm( this, "choosetable", TRUE );
    //QStringList tablelist = db.getTableNames();
    //if (tablelist.empty()){
    //    QMessageBox::information( this, applicationName, "There are no tables to edit in this database." );
    //    return;
    //}
    //tableForm->populateOptions( tablelist );
    //if ( tableForm->exec() ) {
    //statement.append(tableForm->option);
    editTableForm * edTableForm = new editTableForm( this );
    edTableForm->setModal(true);
    //send table name ? or handle it all from here?
    edTableForm->setActiveTable(&db, tableToEdit);
    edTableForm->exec();
    //check modified status
    if (edTableForm->modified)
    {
        populateStructure();
        resetBrowser();
    }
    // }
}

void mainForm::deleteIndex()
{
    if (!db.isOpen()){
        QMessageBox::information( this, QApplication::applicationName(), "There is no database opened." );
        return;
    }
    deleteIndexForm * indexForm = new deleteIndexForm( this );
    indexForm->setModal(true);
    indexForm->populateOptions( db.getIndexNames());
    if ( indexForm->exec() ) {
        QString statement = "DROP INDEX ";
        statement.append(indexForm->option);
        statement.append(";");
        if (!db.executeSQL( statement)){
            QString error = "Error: could not delete the index. Message from database engine:  ";
            error.append(db.lastErrorMessage);
            QMessageBox::warning( this, QApplication::applicationName(), error );
        } else {
            populateStructure();
            resetBrowser();
        }
    }

}


void mainForm::copy()
{
    QWidget * t =dataTable->cellWidget(dataTable->currentRow(), dataTable->currentColumn());
    if (t!=0){
        if (QString(t->metaObject()->className()) == "QLineEdit"){
            /*we are in edit mode*/
            if (t->hasFocus()){
                QLineEdit * le = (QLineEdit *) t;
                le->copy();
            }
        }
    }
    if (editGoto->hasFocus())
        editGoto->copy();
}


void mainForm::paste()
{
    QWidget * t =dataTable->cellWidget(dataTable->currentRow(), dataTable->currentColumn());
    if (t!=0){
        if ( QString(t->metaObject()->className()) == "QLineEdit" ){
            /*we are in edit mode*/
            if (t->hasFocus()){
                QLineEdit * le = (QLineEdit *) t;
                le->paste();}
        }
    }
    if (editGoto->hasFocus())
        editGoto->paste();
}


void mainForm::helpWhatsThis()
{
    QWhatsThis::enterWhatsThisMode ();
}


void mainForm::helpAbout()
{
    aboutForm * aForm = new aboutForm( this );
    aForm ->exec() ;
}


void mainForm::updateRecordText(int row, int col, QString newtext)
{
    if (!db.updateRecord(row, col, newtext)){
        QMessageBox::information( this, QApplication::applicationName(), "Data could not be updated" );
    }

    rowList tab = db.browseRecs;
    QStringList& rt = tab[row];
    QString& cv = rt[col+1];//must account for rowid

    QString content = cv ;
    QString firstline = content.section( '\n', 0,0 );
    if (content.length()>14)
    {
        firstline.truncate(14);
        firstline.append("...");
    }
    dataTable->setItem( row - recAtTop, col, new QTableWidgetItem(firstline));
}

void mainForm::logWinAway()
{
    sqlLogAction->toggle();
}

void mainForm::editWinAway()
{
    editWin->hide();
    activateWindow();
    dataTable->setRangeSelected( QTableWidgetSelectionRange(editWin->curRow - recAtTop, editWin->curCol, editWin->curRow- recAtTop, editWin->curCol), true);
}



void mainForm::editText(int row, int col)
{
    rowList tab = db.browseRecs;
    QStringList& rt = tab[row];
    QString cv = rt[col+1];//must account for rowid

    editWin->loadText(cv , row, col);
    editWin ->show();
}



void mainForm::doubleClickTable( int row, int col )
{
    if ((row==-1) || (col==-1)){
        qDebug("no cell selected");
        return;
    }

    int realRow = row + recAtTop;

    editText(realRow , col);
}


void mainForm::executeQuery()
{
    QString query = db.GetEncodedQString(sqlTextEdit->toPlainText());
    if (query.isEmpty())
    {
        QMessageBox::information( this, QApplication::applicationName(), "Query string is empty" );
        return;
    }
    //log the query
    db.logSQL(query, kLogMsg_User);
    sqlite3_stmt *vm;
    const char *tail=NULL;
    int ncol;
    int err=0;
    QString lastErrorMessage = QString("No error");
    //Accept multi-line queries, by looping until the tail is empty
    while (1) {
        if (tail!=NULL) {
            query = QString(tail);
        }
        queryResultListModel->removeRows(0, queryResultListModel->rowCount());
        queryResultListModel->setHorizontalHeaderLabels(QStringList());
        queryResultListModel->setVerticalHeaderLabels(QStringList());

        err=sqlite3_prepare(db._db,query.toUtf8(),query.length(),
                            &vm, &tail);
        if (err == SQLITE_OK){
            db.setDirty(true);
            int rownum = 0;
            bool mustCreateColumns = true;
            while ( sqlite3_step(vm) == SQLITE_ROW ){
                ncol = sqlite3_data_count(vm);
                //setup num of cols here for display grid
                if (mustCreateColumns)
                {
                    QStringList headerList;
                    for (int e=0; e<ncol; e++)
                        headerList = headerList << sqlite3_column_name(vm, e);
                    queryResultListModel->setHorizontalHeaderLabels(headerList);
                    mustCreateColumns = false;
                }
                for (int e=0; e<ncol; e++){
                    char * strresult = 0;
                    QString rv;
                    strresult = (char *) sqlite3_column_text(vm, e);
                    rv = QString(strresult);
                    //show it here
                    QString decoded = db.GetDecodedQString(rv);
                    QString firstline = decoded.section( '\n', 0,0 );
                    if (firstline.length()>MAX_DISPLAY_LENGTH)
                    {
                        firstline.truncate(MAX_DISPLAY_LENGTH);
                        firstline.append("...");
                    }
                    queryResultListModel->setItem(rownum, e, new QStandardItem(QString(firstline)));
                }
                queryResultListModel->setVerticalHeaderItem(rownum, new QStandardItem(QString::number(rownum + 1)));
                rownum++;
            }
            sqlite3_finalize(vm);
        }else{
            lastErrorMessage = QString (sqlite3_errmsg(db._db));
        }
        queryErrorLineEdit->setText(lastErrorMessage);
        queryResultTableView->resizeColumnsToContents();

        if ((!tail)||(*tail==0)) break;
        if(err!=SQLITE_OK) break;
    }
}


void mainForm::mainTabSelected(const QString & tabname)
{
    if ((mainTab->currentIndex() == 0)||(mainTab->currentIndex() == 1))
    {
        populateStructure();
        resetBrowser();
    }
}


void mainForm::toggleLogWindow( bool enable )
{
    if (enable){
        logWin->show();
    } else {
        logWin->hide();
    }
}


void mainForm::importTableFromCSV()
{
    if (!db.isOpen()){
        QMessageBox::information( this, QApplication::applicationName(), "There is no database opened. Please open or create a new database file first." );
        return;
    }

    // Not needed anymore due to nested savepoints
    /*     if (db.getDirty())
     {
  QString msg = "Database needs to be saved before the import operation.\nSave current changes and continue?";
  if (QMessageBox::question( this, applicationName ,msg, QMessageBox::Yes, QMessageBox::No)==QMessageBox::Yes)
  {
     db.save();
  } else {
   return;
  }
    }*/

    QString wFile = QFileDialog::getOpenFileName(
                this,
                "Choose a text file",
                defaultlocation,
                "Text files (*.csv *.txt)");

    if (QFile::exists(wFile) )
    {
        importCSVForm * csvForm = new importCSVForm( this );
        csvForm->initialize(wFile, &db);
        if ( csvForm->exec() ) {
            populateStructure();
            resetBrowser();
            QMessageBox::information( this, QApplication::applicationName(), "Import completed" );
        }
    }
}

void mainForm::exportTableToCSV()
{
    if (!db.isOpen()){
        QMessageBox::information( this, QApplication::applicationName(), "There is no database opened to export" );
        return;
    }
    exportTableCSVForm * exportForm = new exportTableCSVForm( this );
    exportForm->populateOptions( db.getTableNames());
    if ( exportForm->exec() ) {
        //qDebug(exportForm->option);
        //load our table
        db.browseTable(exportForm->option);

        QString fileName = QFileDialog::getSaveFileName(
                    this,
                    "Choose a filename to export data",
                    defaultlocation,
                    "Text files (*.csv *txt)");

        if (fileName.size() > 0)
        {
            QFile file(fileName);
            if ( file.open( QIODevice::WriteOnly ) )
            {
                char quote = '"';
                char sep = ',';
                char feed = 10;
                int colNum = 0;
                int colCount = 0;
                QTextStream stream( &file );
                //fieldnames on first row
                QStringList fields = db.browseFields;
                colCount = fields.count();
                for ( QStringList::Iterator ct = fields.begin(); ct != fields.end(); ++ct ) {
                    stream << quote;
                    stream << *ct;
                    stream << quote;
                    colNum++;
                    if (colNum<colCount)
                    {
                        stream << sep;
                    } else {
                        stream << feed;
                        colNum = 0;
                    }
                }

                //now export data
                rowList tab = db.browseRecs;

                //int dcols =0;
                QString rowLabel;
                for ( int i=0; i<tab.size(); ++i )
                {
                    QStringList& rt = tab[i];
                    for ( int e=1; e<rt.size(); ++e ) {
                        QString content = rt[e];
                        stream<< quote;
                        QChar qquote = quote;
                        content.replace(quote, QString(qquote).append(qquote));
                        stream<< content;
                        stream<< quote;
                        colNum++;
                        if (colNum<colCount)
                        {
                            stream << sep;
                        } else {
                            stream << feed;
                            colNum = 0;
                        }
                    }
                }

                file.close();
                QMessageBox::information( this, QApplication::applicationName(), "Export completed" );
            }
        }
        populateStructure();
        resetBrowser();
    }
}


void mainForm::dbState( bool dirty )
{
    fileSaveAction->setEnabled(dirty);
    fileRevertAction->setEnabled(dirty);
}


void mainForm::fileSave()
{
    if (db.isOpen()){
        db.save();
        //dbStatusBar->showMessage("Date written to file", 4000)
    }
}


void mainForm::fileRevert()
{
    if (db.isOpen()){
        QString msg = "Are you sure you want to undo all changes made to the database file \n\n<b> ";
        msg.append(db.curDBFilename);
        msg.append("</b>\n since the last save?");
        if (QMessageBox::question( this, QApplication::applicationName() ,msg, QMessageBox::Yes, QMessageBox::No)==QMessageBox::Yes)
        {
            db.revert();
            populateStructure();
            resetBrowser();
        }
    }
}


void mainForm::exportDatabaseToSQL()
{
    if (!db.isOpen()){
        QMessageBox::information( this, QApplication::applicationName(), "There is no database opened to export" );
        return;
    }

    QString fileName = QFileDialog::getSaveFileName(
                this,
                "Choose a filename to export",
                defaultlocation,
                "Text files (*.sql *txt)");

    if (fileName.size() > 0)
    {
        if (!db.dump(fileName))
        {
            QMessageBox::information( this, QApplication::applicationName(), "Could not create export file" );
        } else {
            QMessageBox::information( this, QApplication::applicationName(), "Export completed" );
        }
    }
}


void mainForm::importDatabaseFromSQL()
{
    QString fileName = QFileDialog::getOpenFileName(
                this,
                "Choose a file to import",
                defaultlocation,
                "Text files (*.sql *txt)");

    if (fileName.size() > 0)
    {
        QString msg = "Do you want to create a new database file to hold the imported data?\nIf you answer NO we will attempt to import data in the .sql file to the current database.";
        if (QMessageBox::question( this, QApplication::applicationName() ,msg, QMessageBox::Yes, QMessageBox::No)==QMessageBox::Yes)
        {
            QString newDBfile = QFileDialog::getSaveFileName(
                        this,
                        "Choose a filename to save under",
                        defaultlocation);
            if (QFile::exists(newDBfile) )
            {
                QString err = "File ";
                err.append(newDBfile);
                err.append(" already exists. Please choose a different name");
                QMessageBox::information( this, QApplication::applicationName() ,err);
                return;
            }
            if (!fileName.isNull())
            {
                db.create(newDBfile);
            }
        }
        int lineErr;
        if (!db.reload(fileName, &lineErr))
        {
            QMessageBox::information( this, QApplication::applicationName(), QString("Error importing data at line %1").arg(lineErr) );
        }
        else
        {
            QMessageBox::information( this, QApplication::applicationName(), "Import completed" );
        }
        populateStructure();
        resetBrowser();
    }
}


void mainForm::openPreferences()
{
    preferencesForm * prefForm = new preferencesForm( this );
    if ( prefForm->exec() ) {
        updatePreferences();
        resetBrowser();
    }
}

void mainForm::updatePreferences()
{
    preferencesForm * prefForm = new preferencesForm( this );
    prefForm->loadSettings();

    if (prefForm->defaultencoding=="Latin1")
    {
        db.setEncoding(kEncodingLatin1);
    } else {
        db.setEncoding(kEncodingUTF8);
    }
    db.setDefaultNewData(prefForm->defaultnewdata);
    defaultlocation= prefForm->defaultlocation;
    editWin->defaultlocation = defaultlocation;
    editWin->setTextFormat(prefForm->defaulttext);
}

//******************************************************************
//** Tree Events
//******************************************************************

//** Db Tree Context Menu
void mainForm::on_tree_context_menu(const QPoint &qPoint){
    if( !dbTreeWidget->selectionModel()->hasSelection() ){
        return;
    }
    QTreeWidgetItem *cItem = dbTreeWidget->currentItem();

    if(cItem->text(1) == "table"){
        editDeleteTableActionPopup->setDisabled(false);
        editModifyTableActionPopup->setDisabled(false);
        popupTableMenu->exec( dbTreeWidget->mapToGlobal(qPoint) );

    }else if(cItem->text(1) == "field"){
        popupFieldMenu->exec( dbTreeWidget->mapToGlobal(qPoint) );
    }
}
//** Tree selection changed
void mainForm::on_tree_selection_changed(){
    if (!dbTreeWidget->selectionModel()->hasSelection()){
        editDeleteTableActionPopup->setEnabled(false);
        editModifyTableActionPopup->setEnabled(false);
        editAddFieldActionPopup->setEnabled(false);
        editModifyFieldActionPopup->setEnabled(false);
        editDeleteFieldActionPopup->setEnabled(false);
        return;
    }

    if(dbTreeWidget->currentItem()->text(1) == "table"){
        editDeleteTableActionPopup->setEnabled(true);
        editModifyTableActionPopup->setEnabled(true);
        editAddFieldActionPopup->setEnabled(true);
        editModifyFieldActionPopup->setEnabled(false);
        editDeleteFieldActionPopup->setEnabled(false);

    }else if(dbTreeWidget->currentItem()->text(1) == "field"){
        editAddFieldActionPopup->setEnabled(false);
        editDeleteTableActionPopup->setEnabled(false);
        editModifyTableActionPopup->setEnabled(false);
        editModifyFieldActionPopup->setEnabled(true);
        editDeleteFieldActionPopup->setEnabled(true);
    }
}


void mainForm::on_add_field(){
    qDebug("YES");
    //if( !dbTreeWidget->currentItem() ){
    //   return;
    //}
    //QTreeWidgetItem *item = dbTreeWidget->currentItem();
    editFieldForm *fieldForm = new editFieldForm( this );
    //qDebug(item->text(2));
    fieldForm->setInitialValues(true, dbTreeWidget->currentItem()->text(0), "", "TEXT");
    fieldForm->setDB(this->db);
    if (fieldForm->exec())
    {
        //modified = true;
        //do the sql rename here
        //populateStructure();
        qDebug((fieldForm->field_name + fieldForm->field_type).toUtf8());
        //* find parent item
        populateStructure();
        //       QTreeWidgetItem *parentItem = dbTreeWidget->findItems()
        return;
        QTreeWidgetItem *newItem = new QTreeWidgetItem(dbTreeWidget->currentItem());
        newItem->setText(0, fieldForm->field_name);
        newItem->setText(1, "field");
        newItem->setText(2, fieldForm->field_type);
    }
}
void mainForm::on_edit_field(){
    qDebug("YES");
    if( !dbTreeWidget->currentItem() ){
        return;
    }
    QTreeWidgetItem *item = dbTreeWidget->currentItem();
    editFieldForm *fieldForm = new editFieldForm( this );
    qDebug(item->text(2).toUtf8());
    fieldForm->setInitialValues(false, "TABLE_NAME", item->text(0), item->text(2));
    fieldForm->setDB(this->db);
    if (fieldForm->exec())
    {
        //modified = true;
        //do the sql rename here
        //qDebug(fieldForm->name + fieldForm->type);
        item->setText(0,fieldForm->field_name);
        item->setText(2,fieldForm->field_type);
    }
}

void mainForm::openRecentFile()
{
    QAction *action = qobject_cast<QAction *>(sender());
    if (action)
        fileOpen(action->data().toString());
}

void mainForm::updateRecentFileActions()
{
    QSettings settings(QApplication::organizationName(), g_sApplicationNameShort);
    QStringList files = settings.value("recentFileList").toStringList();


    int numRecentFiles = qMin(files.size(), (int)MaxRecentFiles);

    for (int i = 0; i < numRecentFiles; ++i) {
        QString text = tr("&%1 %2").arg(i + 1).arg(files[i]);
        recentFileActs[i]->setText(text);
        recentFileActs[i]->setData(files[i]);
        recentFileActs[i]->setVisible(true);
    }
    for (int j = numRecentFiles; j < MaxRecentFiles; ++j)
        recentFileActs[j]->setVisible(false);

    recentSeparatorAct->setVisible(numRecentFiles > 0);
}

void mainForm::setCurrentFile(const QString &fileName)
{
    setWindowFilePath(fileName);

    QSettings settings(QApplication::organizationName(), g_sApplicationNameShort);
    QStringList files = settings.value("recentFileList").toStringList();
    files.removeAll(fileName);
    files.prepend(fileName);
    while (files.size() > MaxRecentFiles)
        files.removeLast();

    settings.setValue("recentFileList", files);

    foreach (QWidget *widget, QApplication::topLevelWidgets()) {
        mainForm *mainWin = qobject_cast<mainForm *>(widget);
        if (mainWin)
            mainWin->updateRecentFileActions();
    }
}

void mainForm::dragEnterEvent(QDragEnterEvent *event)
{
    if( event->mimeData()->hasFormat("text/uri-list") )
            event->acceptProposedAction();
}

void mainForm::dropEvent(QDropEvent *event)
{
    QList<QUrl> urls = event->mimeData()->urls();

    if( urls.isEmpty() )
        return;

    QString fileName = urls.first().toLocalFile();

    if( !fileName.isEmpty() && fileName.endsWith("db") )
            fileOpen(fileName);
}