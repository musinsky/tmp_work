// 2019-07-09
// Jan Musinsky

//#include <TROOT.h>
//#include <TH1.h>

TH1 *res_GetHisto(const char *fname, const char *hname)
{
  TH1 *histo = (TH1 *)(gROOT->FindObject(hname));
  if (histo) delete histo;
  gROOT->SetBatch(kTRUE);
  gROOT->ProcessLine(TString::Format(".x %s", fname));
  histo = (TH1 *)(gROOT->FindObject(hname));
  if (!histo)
    Printf("histogram \"%s\" does not exist", hname);
  delete gROOT->GetListOfCanvases()->Last();
  gROOT->SetBatch(kFALSE);
  return histo;
}
