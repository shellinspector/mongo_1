//---------------------------------------------------------------------------

#include <vcl.h>
#pragma hdrstop

#include "DB_MONGO.h"
//---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma resource "*.dfm"
TMatchEdit *MatchEdit;
//---------------------------------------------------------------------------
__fastcall TMatchEdit::TMatchEdit(TComponent* Owner)
	: TForm(Owner)
{
}

//---------------------------------------------------------------------------

void __fastcall TMatchEdit::ConnectDBExecute(TObject *Sender)
{
	//FDConnection1->Connected = true;
	FDConnection1->Open();
	FCon = (TMongoConnection*)FDConnection1->CliObj;
	FEnv = FCon->Env;
}

//---------------------------------------------------------------------------
void __fastcall TMatchEdit::DumpCursor(_di_IMongoCursor ACrs)
{
/*
    	while(ACrs->Next()) {
    		Memo1->Lines->Add(ACrs->Doc->AsJSON);
		}
*/
}

void __fastcall TMatchEdit::FormClose(TObject *Sender, TCloseAction &Action)
{
	if (MessageDlg("Close application ?", mtConfirmation, TMsgDlgButtons() << mbYes << mbNo,0) == mrYes)
	{
		FDConnection1->Close();
		Action = caFree;
	}
	else
	{
		Action = caNone;
    }
}

//---------------------------------------------------------------------------

void __fastcall TMatchEdit::AddDocumentRecordExecute(TObject *Sender)
{
     // For details see:
	// https://docs.mongodb.org/getting-started/shell/insert/
	std::unique_ptr<TMongoDocument> oDoc(FEnv->NewDoc());
	TMongoCollection * oCol = FCon->GetCollection("configs", "mechanical");
	oCol->RemoveAll();
	// Build new document
	oDoc
	  ->BeginObject("home_position")
		->Add("x", (System::Extended)-73.9557413)
		->Add("y", (System::Extended)-3.3007419)
		->Add("z", (System::Extended)-0.32247416)
	  ->EndObject()
	  ->BeginArray("array_data")
		->Add("0",11)
		->Add("0",12)
		->Add("0",13)
	  ->EndArray()
		->Add("config_date", Now())
		->Add("model", ComboBox1->Text)
		->Add("unit_id", String("41704620"));


	// Insert new document into "restaurants" collection in "test" database.
	// This may be done using "fluent" style.
	oCol->Insert(oDoc.get());

	// Find, retrieve and show all documents
	// The query condition may be build using "fluent" style.
	_di_IMongoCursor oCrs = oCol->Find(NULL, TMongoQueryFlags());
	while(oCrs->Next()) {
		Memo1->Lines->Add(oCrs->Doc->AsJSON);
//		Memo1->Text = Memo1->Text + "\n" + oCrs->Doc->AsJSON;
	}

	// Get number of documents in the collection
	Memo1->Lines->Add("Record count " + IntToStr((__int64)oCol->Count()->Value()));
//	Memo1->Text = Memo1->Text + "\nRecord count " + IntToStr((__int64)oCol->Count()->Value());
}

//---------------------------------------------------------------------------

void __fastcall TMatchEdit::FormCreate(TObject *Sender)
{
		MatchEdit->Text = String("{model:{}}");
		SortEdit->Text = String("{config_date:-1}");
		ProjectionEdit->Text = String("{_id:0,model:1,home_position:1,config_date:1}");
}
//---------------------------------------------------------------------------

