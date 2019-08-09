// 2019-07-30
// Jan Musinsky

void DoIt(TH1 *h);

void p1_plus_p2()
{
  gStyle->SetOptStat(0);
  gStyle->SetOptFit(0);
  gStyle->SetGridColor(kGray);

  gROOT->ProcessLine(".x digit_histo_CH2.C");
  gROOT->ProcessLine(".x digit_histo_C.C");
  TH1F *h_CH2 = (TH1F *)(gROOT->FindObject("h1"));
  TH1F *h_C   = (TH1F *)(gROOT->FindObject("h2"));
  TFile *f1D = TFile::Open("vvg_MC_1D.root");
  TH1F *h_MC_dpall = (TH1F *)f1D->Get("h49");

  DoIt(h_CH2);
  DoIt(h_C);
  DoIt(h_MC_dpall);

  TCanvas *c = new TCanvas("c", "c", 0, 0, 1250, 425);
  c->Divide(2, 1, 0.001, 0.001);
  c->cd(1);
  gPad->SetGridx();
  h_CH2->Draw();
  h_C->Draw("same");
  c->cd(2);
  gPad->SetGridx();
  h_MC_dpall->Draw();
  c->cd();
  gPad->Modified();
  gPad->Update();
  c->Print("p1_plus_p2_1.eps");
  c->Print("p1_plus_p2_1.pdf");
  c->Print("p1_plus_p2_1.png");

  TH1F *h_del = (TH1F *)h_CH2->Clone();
  h_del->Add(h_C, -1.0);
  //  h_del->SetBinContent(51,198); // manual correct
  TH1F *h_MC_dpppn = (TH1F *)f1D->Get("h45");
  DoIt(h_del);
  DoIt(h_MC_dpppn);
  h_del->SetLineColor(kViolet-7);

  c = new TCanvas("c2", "c2", 50, 50, 1250, 425);
  c->Divide(2, 1, 0.001, 0.001);
  c->cd(1);
  gPad->SetGridx();
  h_del->Draw();
  c->cd(2);
  gPad->SetGridx();
  h_MC_dpppn->Draw();
  c->cd();
  gPad->Modified();
  gPad->Update();
  c->Print("p1_plus_p2_2.eps");
  c->Print("p1_plus_p2_2.pdf");
  c->Print("p1_plus_p2_2.png");
}

void DoIt(TH1 *h)
{
  h->SetTitle(0);

  // font 42 (helvetica, default) need for h2root histograms
  h->GetXaxis()->SetRangeUser(1.55, 4.45);
  h->GetXaxis()->SetTitle("#it{p}_{1} + #it{p}_{2}, GeV/#it{c}");
  h->GetXaxis()->CenterTitle(kFALSE);
  h->GetXaxis()->SetTitleSize(0.045);
  h->GetXaxis()->SetTitleOffset(0.975);
  h->GetXaxis()->SetTitleFont(42);
  h->GetXaxis()->SetNdivisions(410);
  h->GetXaxis()->SetLabelSize(0.045);
  h->GetXaxis()->SetLabelFont(42);

  //  h->GetYaxis()->SetTitle("entries");
  //  h->GetYaxis()->CenterTitle();
  //  h->GetYaxis()->SetTitleSize(0.045);
  //  h->GetYaxis()->SetTitleOffset(0.975);
  h->GetYaxis()->SetTitleFont(42);
  h->GetYaxis()->SetNdivisions(304);
  h->GetYaxis()->SetLabelSize(0.045);
  h->GetYaxis()->SetLabelFont(42);
}
