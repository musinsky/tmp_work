// 2019-08-01
// Jan Musinsky

void dp_dN()
{
  gStyle->SetOptStat(0);
  gStyle->SetOptFit(0);
  gStyle->SetGridColor(kGray);

  gROOT->ProcessLine(".x digit_histo_dN.C");
  TH1F *h_dN = (TH1F *)(gROOT->FindObject("h7"));
  h_dN->SetMinimum(0);
  h_dN->SetMaximum(500);
  h_dN->SetTitle(0);
  h_dN->GetXaxis()->SetTitle("|#it{t}|, (GeV/#it{c})^{2}");
  h_dN->GetXaxis()->CenterTitle(kFALSE);
  h_dN->GetXaxis()->SetTitleSize(0.045);
  h_dN->GetXaxis()->SetTitleOffset(0.975);
  h_dN->GetXaxis()->SetNdivisions(407);
  h_dN->GetXaxis()->SetLabelSize(0.045);
  h_dN->GetYaxis()->SetNdivisions(409);
  h_dN->GetYaxis()->SetLabelSize(0.045);

  TF1 *fite = new TF1("fite","[0]*TMath::Exp([1]*x)");
  fite->SetParameter(0,  435.6);
  fite->SetParameter(1, -440.9);
  fite->SetNpx(1000);
  fite->SetLineColor(h_dN->GetLineColor());

  TCanvas *c = new TCanvas("c", "c", 0, 0, 700*1.25, 500);
  h_dN->Draw("hist");
  fite->Draw("same");
  gPad->Modified();
  gPad->Update();
  c->Print("dp_dN.eps");
  c->Print("dp_dN.pdf");
  c->Print("dp_dN.png");
}
