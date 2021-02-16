// 2021-02-16
// Jan Musinsky

void DoIt(TH2 *h);

void p1_vs_p2()
{
  gStyle->SetOptStat(0);
  gStyle->SetOptFit(0);
  gStyle->SetGridColor(kGray);
  gStyle->SetPalette(55);
  // gStyle->SetPalette(kGreyScale);
  // TColor::InvertPalette();

  gROOT->ProcessLine(".x digit_histo_2p.C");
  TH2F *h_2p = (TH2F *)(gROOT->FindObject("hh"));
  TFile *f2D = TFile::Open("vvg_MC_2D.root");
  TH2F *h_MC_dpall = (TH2F *)f2D->Get("h63");
  TH2F *h_MC_dpppn = (TH2F *)f2D->Get("h61");

  // fix (remove) bins
  h_MC_dpall->SetBinContent(7, 30, 0);
  h_MC_dpall->SetBinContent(28, 7, 0);
  h_MC_dpppn->SetBinContent(7, 30, 0);
  h_MC_dpppn->SetBinContent(28, 7, 0);

  DoIt(h_2p);
  DoIt(h_MC_dpall);
  DoIt(h_MC_dpppn);

  TCanvas *c1 = new TCanvas("c1", "c1", 0, 0, 390, 800); // histos are squares
  c1->Divide(1, 2, 0.001, 0.001);
  c1->cd(1);
  gPad->SetGrid();
  h_MC_dpall->Draw();
  TText *tex = new TText(0.815, 0.820,"(a)");
  tex->SetNDC();
  tex->SetTextFont(42);
  tex->SetTextAlign(22);
  tex->Draw();
  c1->cd(2);
  gPad->SetGrid();
  h_MC_dpppn->Draw();
  tex = new TText(0.815, 0.820,"(b)");
  tex->SetNDC();
  tex->SetTextFont(42);
  tex->SetTextAlign(22);
  tex->Draw();
  c1->cd();
  gPad->Modified();
  gPad->Update();
  c1->Print("p1_vs_p2_1.eps");
  c1->Print("p1_vs_p2_1.pdf");

  TCanvas *c2 = new TCanvas("c2", "c2", 400, 0, 390, 410); // histo is square
  gPad->SetGrid();
  h_2p->Draw("cont");
  gPad->Modified();
  gPad->Update();
  c2->Print("p1_vs_p2_2.eps");
  c2->Print("p1_vs_p2_2.pdf");
}

void DoIt(TH2 *h)
{
  h->SetTitle(0);
  h->SetMarkerStyle(7);

  // font 42 (helvetica, default) need for h2root histograms
  h->GetXaxis()->SetRangeUser(1.00, 2.25);
  h->GetXaxis()->SetTitle("#it{p}_{1} , GeV/#it{c}");
  h->GetXaxis()->CenterTitle(kFALSE);
  h->GetXaxis()->SetTitleSize(0.045);
  h->GetXaxis()->SetTitleOffset(1.025);
  h->GetXaxis()->SetTitleFont(42);
  h->GetXaxis()->SetNdivisions(310);
  h->GetXaxis()->SetLabelSize(0.045);
  h->GetXaxis()->SetLabelFont(42);

  h->GetYaxis()->SetRangeUser(1.00, 2.25);
  h->GetYaxis()->SetTitle("#it{p}_{2} , GeV/#it{c}");
  h->GetYaxis()->CenterTitle(kFALSE);
  h->GetYaxis()->SetTitleSize(0.045);
  h->GetYaxis()->SetTitleOffset(1.025);
  h->GetYaxis()->SetTitleFont(42);
  h->GetYaxis()->SetNdivisions(310);
  h->GetYaxis()->SetLabelSize(0.045);
  h->GetYaxis()->SetLabelFont(42);
}
