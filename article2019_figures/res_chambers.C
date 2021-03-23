// 2020-05-21
// Jan Musinsky

#include "res_GetHisto.C"

void DoIt(TH1D *h);

void res_chambers()
{
  //  R__LOAD_LIBRARY(res_GetHisto.C);
  TH1D *hs_4 = (TH1D *)res_GetHisto("res_small_OK_orig.C", "tra_3_iter4");
  TH1D *hb_4 = (TH1D *)res_GetHisto("res_big_OK_orig.C", "tra_1_iter4");

  gStyle->SetOptStat(0);
  gStyle->SetOptFit(0);
  gStyle->SetGridColor(kGray);
  DoIt(hs_4);
  DoIt(hb_4);

  TF1 *fit = new TF1("fit", "pol2(0) + gaus(3) + gaus(6)");
  fit->SetLineWidth(2);
  fit->SetNpx(1000);
  fit->SetLineColor(kBlack);
  fit->SetParameters(4500, -750, 135000, 70000, 0, 0.01, 35000, 0, 0.02);

  TCanvas *c = new TCanvas("c", "c", 0, 0, 500, 750);
  c->Divide(1, 2, 0.001, 0.001);
  c->cd(1);
  gPad->SetGridx();
  hs_4->Draw();
  hs_4->Fit(fit, "Q");
  TPaveLabel *pl = new TPaveLabel(0.030, hs_4->GetMaximum()*0.45,
                                  0.115, hs_4->GetMaximum()*0.55,
                                  " #sigma ~ 100 #mum");
  pl->SetFillColor(0);
  pl->SetTextSize(0.66);
  pl->SetBorderSize(1);
  pl->SetLineWidth(0);
  pl->Draw();
  TText *tex = new TText(0.85, 0.85,"(a)");
  tex->SetNDC();
  tex->SetTextFont(42);
  tex->SetTextAlign(22);
  tex->Draw();
  gPad->Modified(); // must be 2x ?! but why ?!
  gPad->Update();
  gPad->Modified();
  gPad->Update();

  c->cd(2);
  gPad->SetGridx();
  hb_4->Draw();
  hb_4->Fit(fit, "Q");
  TPaveLabel *pl2 = new TPaveLabel(0.030, hb_4->GetMaximum()*0.45,
                                   0.115, hb_4->GetMaximum()*0.55,
                                   " #sigma ~ 85 #mum");
  pl2->SetFillColor(0);
  pl2->SetTextSize(0.66);
  pl2->SetBorderSize(1);
  pl2->SetLineWidth(0);
  pl2->Draw();
  TText *tex2 = new TText(0.85, 0.85,"(b)");
  tex2->SetNDC();
  tex2->SetTextFont(42);
  tex2->SetTextAlign(22);
  tex2->Draw();
  gPad->Modified(); // must be 2x ?! but why ?!
  gPad->Update();
  gPad->Modified();
  gPad->Update();
  c->cd();

  c->Print("res_chambers.eps");
  c->Print("res_chambers.pdf");
  //  c->Print("res_chambers.png");
}

void DoIt(TH1D *h)
{
  h->SetFillColor(0);
  h->SetLineColor(kBlack);
  h->SetMaximum(h->GetMaximum()*1.075);
  h->GetXaxis()->SetTitle("#Deltar, cm");
  h->GetXaxis()->CenterTitle(kFALSE);
  h->GetXaxis()->SetRangeUser(-0.125, 0.125);
  h->GetXaxis()->SetTitleSize(0.05);
  h->GetXaxis()->SetTitleOffset(1.00);
  h->GetXaxis()->SetNdivisions(410);
  h->GetXaxis()->SetLabelSize(0.05);
  h->GetYaxis()->SetTitle("N");
  h->GetYaxis()->CenterTitle();
  h->GetYaxis()->SetTitleSize(0.05);
  h->GetYaxis()->SetTitleOffset(1.00);
  h->GetYaxis()->SetNdivisions(405);
  h->GetYaxis()->SetLabelSize(0.05);
}
