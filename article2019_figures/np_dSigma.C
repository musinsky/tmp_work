// 2020-05-22
// Jan Musinsky

void np_dSigma()
{
  gStyle->SetOptStat(0);
  gStyle->SetOptFit(0);
  gStyle->SetGridColor(kGray);

  gROOT->ProcessLine(".x digit_graph_np.C");
  TGraphErrors *gre = (TGraphErrors *)(gROOT->FindObject("bizard0"));
  gDirectory->Remove(gre);
  gre->SetMinimum(20);
  gre->SetMaximum(95);
  gre->SetMarkerStyle(8);
  gre->SetMarkerSize(0.75);
  gre->SetTitle(0);
  // canvas size from dp_dN.C is 500, 400 vs. 500, 350 from this
  Double_t rr = 400./350.;
  gre->GetXaxis()->SetRangeUser(1.415, 1.95);
  gre->GetXaxis()->SetTitle("#it{p}, GeV/#it{c}");
  gre->GetXaxis()->CenterTitle(kFALSE);
  gre->GetXaxis()->SetTitleSize(0.045*rr);
  gre->GetXaxis()->SetTitleOffset(0.925);
  gre->GetXaxis()->SetNdivisions(410);
  gre->GetXaxis()->SetLabelSize(0.045*rr);
  gre->GetYaxis()->SetTitle("#it{d#sigma/dt}|_{#it{t = 0}}, #frac{mb}{(GeV/#it{c})^{2}}");
  gre->GetYaxis()->CenterTitle(kTRUE);
  gre->GetYaxis()->SetTitleSize(0.045*rr);
  gre->GetYaxis()->SetTitleOffset(0.975);
  gre->GetYaxis()->SetNdivisions(407);
  gre->GetYaxis()->SetLabelSize(0.045*rr);

  TF1 *fe = new TF1("fe", "[0]*TMath::Exp([1]*x)", 1.0, 2.0);
  fe->SetParameter(0, 702.1713);
  fe->SetParameter(1, -1.532917);
  fe->SetNpx(1000);
  fe->SetLineColor(gre->GetLineColor());

  TCanvas *c = new TCanvas("c", "c", 0, 0, 500, 350);
  // default margin 0.10 (all direction)
  c->SetLeftMargin(0.12);
  c->SetRightMargin(0.08); // same as dp_dN.C
  c->SetTopMargin(0.02);   // same as dp_dN.C
  gre->Draw("ap");
  fe->Draw("same");
  gPad->SetGrid();
  gPad->Modified();
  gPad->Update();
  c->Print("np_dSigma.eps");
  c->Print("np_dSigma.pdf");
  //  c->Print("np_dSigma.png");
}
