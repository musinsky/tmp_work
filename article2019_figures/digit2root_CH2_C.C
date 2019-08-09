// 2019-08-01
// Jan Musinsky

TH1F *digit(const char *name, Int_t col)
{
  TGraph *g = new TGraph(TString::Format("digit_%s.csv", name));
  g->SetMarkerStyle(7);
  g->SetMarkerColor(col);
  g->SetMinimum(-100);
  g->Draw("AP");

  TH1F *h1 = new TH1F(TString::Format("h_%s", name), name, 100, 1.5, 4.5);
  h1->SetLineColor(col);

  Int_t bin, value;
  for (Int_t i = 0; i < g->GetN(); i++) {
    bin   = h1->FindFixBin(g->GetX()[i]);
    value = g->GetY()[i];
    h1->SetBinContent(bin, value);
  }

  for (Int_t i = 0; i < h1->GetNbinsX(); i++)
    if (h1->GetBinContent(i) <= 0) h1->SetBinContent(i, 1);

  h1->Draw("same");
  gPad->SetGridx();
  return h1;
}

void digit2root_CH2_C()
{
  TCanvas *c1 = new TCanvas();
  c1->Divide(1, 2);
  c1->cd(1);
  digit("CH2", kRed);
  c1->cd(2);
  digit("C", kBlue);
  c1->cd();
}
