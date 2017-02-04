//---------------------------------------------------------------------------

#ifndef DB_MONGOH
#define DB_MONGOH
//---------------------------------------------------------------------------
#include <System.Classes.hpp>
#include <Vcl.Controls.hpp>
#include <Vcl.StdCtrls.hpp>
#include <Vcl.Forms.hpp>
#include <Data.DB.hpp>
#include <System.Actions.hpp>
#include <System.ImageList.hpp>
#include <Vcl.ActnList.hpp>
#include <Vcl.ComCtrls.hpp>
#include <Vcl.DBGrids.hpp>
#include <Vcl.Grids.hpp>
#include <Vcl.ImgList.hpp>
#include <Vcl.ToolWin.hpp>
#include <Vcl.ValEdit.hpp>
#include <FireDAC.Comp.Client.hpp>
#include <FireDAC.Comp.DataSet.hpp>
#include <FireDAC.DApt.Intf.hpp>
#include <FireDAC.DatS.hpp>
#include <FireDAC.Phys.hpp>
#include <FireDAC.Phys.Intf.hpp>
#include <FireDAC.Phys.MongoDBDataSet.hpp>
#include <FireDAC.Stan.Async.hpp>
#include <FireDAC.Stan.Def.hpp>
#include <FireDAC.Stan.Error.hpp>
#include <FireDAC.Stan.Intf.hpp>
#include <FireDAC.Stan.Option.hpp>
#include <FireDAC.Stan.Param.hpp>
#include <FireDAC.Stan.Pool.hpp>
#include <FireDAC.UI.Intf.hpp>
#include <FireDAC.VCLUI.Wait.hpp>
#include <FireDAC.Phys.MongoDB.hpp>
#include <FireDAC.Phys.MongoDBDef.hpp>
#include <FireDAC.Phys.MongoDBWrapper.hpp>
#include <System.JSON.BSON.hpp>
#include <System.JSON.Builders.hpp>
#include <System.JSON.Readers.hpp>
#include <System.JSON.Types.hpp>
#include <System.Rtti.hpp>
#include <IdBaseComponent.hpp>
#include <IdDateTimeStamp.hpp>
#include <memory>
//---------------------------------------------------------------------------
class TMatchEdit : public TForm
{
__published:	// IDE-managed Components
	TEdit *MatchEdit;
	TEdit *SortEdit;
	TEdit *ProjectionEdit;
	TLabel *Label1;
	TLabel *Label2;
	TLabel *Label3;
	TDBGrid *DBGrid1;
	TValueListEditor *ValueListEditor1;
	TComboBox *ComboBox1;
	TActionList *ActionList1;
	TLabel *Label4;
	TLabel *Label5;
	TToolBar *ToolBar1;
	TImageList *ImageList1;
	TToolButton *ToolButton1;
	TMemo *Memo1;
	TToolButton *ToolButton3;
	TToolButton *ToolButton5;
	TToolButton *ToolButton9;
	TToolButton *ToolButton11;
	TToolButton *ToolButton2;
	TAction *ConnectDB;
	TFDConnection *FDConnection1;
	TFDMongoQuery *FDMongoQuery1;
	TDataSource *DataSource1;
	TIdDateTimeStamp *IdDateTimeStamp1;
	TLabel *Label6;
	TAction *AddDocumentRecord;
	TAction *SearchRecord;

	void __fastcall ConnectDBExecute(TObject *Sender);
	void __fastcall FormClose(TObject *Sender, TCloseAction &Action);

	void __fastcall AddDocumentRecordExecute(TObject *Sender);
	void __fastcall FormCreate(TObject *Sender);



private:	// User declarations
	TMongoConnection * FCon;
	TMongoEnv * FEnv;
	void __fastcall DumpCursor(_di_IMongoCursor ACrs);
public:		// User declarations
	__fastcall TMatchEdit(TComponent* Owner);
};
//---------------------------------------------------------------------------
extern PACKAGE TMatchEdit *MatchEdit;
//---------------------------------------------------------------------------
#endif
