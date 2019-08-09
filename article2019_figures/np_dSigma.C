// 2019-08-08
// Jan Musinsky

void np_dSigma()
{
  gStyle->SetOptStat(0);
  gStyle->SetOptFit(0);
  gStyle->SetGridColor(kGray);

  gROOT->ProcessLine(".x digit_graph_np.C");
  TGraphErrors *gre = (TGraphErrors *)(gROOT->FindObject("bizard0"));
  gDirectory->Remove(gre);
  gre->SetMinimum(0);
  gre->SetMaximum(90);
  gre->SetMarkerStyle(8);
  gre->SetTitle(0);
  //  gre->GetXaxis()->SetRangeUser(1.425, 1.975);
  gre->GetXaxis()->SetRangeUser(1.415, 1.95);
  gre->GetXaxis()->SetTitle("#it{p}, GeV/#it{c}");
  gre->GetXaxis()->CenterTitle(kFALSE);
  gre->GetXaxis()->SetTitleSize(0.045);
  gre->GetXaxis()->SetTitleOffset(0.975);
  gre->GetXaxis()->SetNdivisions(410);
  gre->GetXaxis()->SetLabelSize(0.045);
  gre->GetYaxis()->SetTitle("#frac{d#sigma}{dt} #void8_{ t = 0}, #frac{mb}{(GeV/#it{c})^{2}}");
  gre->GetYaxis()->CenterTitle(kTRUE);
  gre->GetYaxis()->SetTitleSize(0.045);
  gre->GetYaxis()->SetTitleOffset(0.975);
  gre->GetYaxis()->SetNdivisions(410);
  gre->GetYaxis()->SetLabelSize(0.045);

  TF1 *fe = new TF1("fe", "[0]*TMath::Exp([1]*x)", 1.0, 2.0);
  fe->SetParameter(0, 702.1713);
  fe->SetParameter(1, -1.532917);
  fe->SetNpx(1000);
  fe->SetLineColor(gre->GetLineColor());

  TCanvas *c = new TCanvas("c", "c", 0, 0, 700*1.25, 500);
  gre->Draw("ap");
  fe->Draw("same");
  gPad->Modified();
  gPad->Update();
  c->Print("np_dSigma.eps");
  c->Print("np_dSigma.pdf");
  c->Print("np_dSigma.png");
}
