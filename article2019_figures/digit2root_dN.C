// 2019-08-01
// Jan Musinsky

void digit2root_dN()
{
  TGraph *g = new TGraph("digit_dN.csv");
  g->SetMarkerStyle(7);
  g->SetMinimum(0);
  g->Draw("AP");

  TH1F *h7 = new TH1F("h7", "dN", 80, 0.0, 0.008);
  Int_t bin;
  Double_t value;
  for (Int_t i = 0; i < g->GetN(); i++) {
    bin   = h7->FindFixBin(g->GetX()[i]);
    value = g->GetY()[i];
    h7->SetBinContent(bin, value);
    h7->SetBinError(bin, TMath::Sqrt(value)*1.33); // + i*0.1);
  }
  h7->Draw("same");
  gPad->SetGrid();
}
