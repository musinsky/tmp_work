// 2019-08-06
// Jan Musinsky

void digit2root_2p()
{
  //  gROOT->ProcessLine(".x c1.C");
  gROOT->ProcessLine(".x digit_2p.C");
  TGraph *gred     = (TGraph *)gROOT->FindObject("Graph0");
  TGraph *gblue    = (TGraph *)gROOT->FindObject("Graph1");
  TGraph *gblack   = (TGraph *)gROOT->FindObject("Graph2");
  TGraph *gmagenta = (TGraph *)gROOT->FindObject("Graph3");
  TGraph *ggreen   = (TGraph *)gROOT->FindObject("Graph4");

  TH2F *hh = new TH2F("hh", "hh", 40*2, 1.0, 2.4, 40*2, 1.0, 2.4);
  Double_t x, y;
  Int_t ii;
  gRandom->SetSeed(12345);

  for (Int_t r = 0; r < 10000*4; r++) { // center
    x = gRandom->Gaus(3.5/2., 0.5*1.0);
    y = gRandom->Gaus(3.5/2., 0.5*1.0);
    ii = gblack->IsInside(x, y);
    if (ii == 1) hh->Fill(x, y);
  }

  for (Int_t r = 0; r < 50000*4; r++) {
    x = gRandom->Gaus(3.5/2., 0.5*1.5);
    y = gRandom->Gaus(3.5/2., 0.5*1.5);
    ii = gmagenta->IsInside(x, y);
    if (ii == 1) hh->Fill(x, y);
  }

  for (Int_t r = 0; r < 90000*4; r++) {
    x = gRandom->Gaus(3.5/2. + 0.1, 0.5*1.75);
    y = gRandom->Gaus(3.5/2. + 0.1, 0.5*1.75);
    ii = ggreen->IsInside(x, y);
    if (ii == 1) hh->Fill(x, y);
  }

  for (Int_t r = 0; r < 10000*4; r++) { // tail
    x = gRandom->Gaus(3.5/2., 0.5*1);
    y = gRandom->Gaus(3.5/2., 0.5*1);
    ii = gred->IsInside(x, y);
    if (ii == 1) hh->Fill(x, y);
  }

  for (Int_t r = 0; r < 2000*4; r++) {
    x = gRandom->Gaus(3.5/2., 0.5*1);
    y = gRandom->Gaus(3.5/2., 0.5*1);
    ii = gblue->IsInside(x, y);
    if (ii == 1) hh->Fill(x, y);
  }

  //  hh->Draw("same, cont1");
  hh->Draw("cont");
  gPad->SetGrid();
}
