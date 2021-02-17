// 2021-02-17
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
  TH1F *h_MC_dpppn = (TH1F *)f1D->Get("h45");
  TH1F *h_del = (TH1F *)h_CH2->Clone();
  h_del->Add(h_C, -1.0);

  DoIt(h_CH2);
  DoIt(h_C);
  DoIt(h_MC_dpall);
  DoIt(h_MC_dpppn);
  DoIt(h_del);
  //  h_del->SetBinContent(51,198); // manual correct

  TCanvas *c = new TCanvas("c", "c", 0, 0, 500-5, 750/2+10);
  gPad->SetGridx();
  h_CH2->SetLineColor(kBlack);
  h_CH2->SetLineStyle(9);
  h_CH2->SetMinimum(-75);
  h_C->SetLineColor(kBlack);
  h_C->SetLineStyle(2);
  h_del->SetLineColor(kBlack);
  h_del->SetLineStyle(1);
  h_del->SetLineWidth(2);
  h_CH2->Draw();
  h_C->Draw("same");
  h_del->Draw("same");
  TLegend *legend = new TLegend(0.19, 0.60, 0.49, 0.80);
  legend->SetMargin(0.40);
  legend->SetTextSize(0.04);
  legend->SetLineWidth(0);
  // !!! canvas = png != pdf !!!
  legend->AddEntry(h_CH2, "target CH_{2}", "l");
  legend->AddEntry(h_C,   "target C", "l");
  legend->AddEntry(h_del, "CH_{2}#minus  C", "l");
  //  legend->AddEntry((TObject *)nullptr, "", ""); // vertical align
  legend->Draw();
  gPad->Modified();
  gPad->Update();
  c->Print("p1_plus_p2_1.eps");
  c->Print("p1_plus_p2_1.pdf");

  c = new TCanvas("c2", "c2", 500, 0, 500-5, 750);
  c->Divide(1, 2, 0.001, 0.001);
  c->cd(1);
  gPad->SetGridx();
  h_MC_dpall->Draw();
  TText *tex = new TText(0.85, 0.85,"(a)");
  tex->SetNDC();
  tex->SetTextFont(42);
  tex->SetTextAlign(22);
  tex->Draw();
  c->cd(2);
  gPad->SetGridx();
  h_MC_dpppn->Draw();
  tex = new TText(0.85, 0.85,"(b)");
  tex->SetNDC();
  tex->SetTextFont(42);
  tex->SetTextAlign(22);
  tex->Draw();
  c->cd();
  gPad->Modified();
  gPad->Update();
  c->Print("p1_plus_p2_2.eps");
  c->Print("p1_plus_p2_2.pdf");
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
  h->GetYaxis()->SetTitle("N");
  h->GetYaxis()->CenterTitle();
  h->GetYaxis()->SetTitleSize(0.045);
  h->GetYaxis()->SetTitleOffset(0.975);
  h->GetYaxis()->SetTitleFont(42);
  h->GetYaxis()->SetNdivisions(304);
  h->GetYaxis()->SetLabelSize(0.045);
  h->GetYaxis()->SetLabelFont(42);
}
