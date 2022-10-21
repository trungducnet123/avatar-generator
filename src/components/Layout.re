open Helmet;

[@bs.module "gatsby"] external useStaticQuery: string => 'a = "useStaticQuery";

%bs.raw
{|
    import  {graphql}  from "gatsby"
    import 'normalize.css'
    import './layout.css'
    import './fonts.css'
    import './text.css'
|};

type siteMetadataType = {title: string};
type siteType = {siteMetadata: siteMetadataType};
type queryResponseType = {site: siteType};

type metaItem =
  | MetaWithName(string, string)
  | MetaWithProperty(string, string);

type meta = array(metaItem);

let meta = [|
  MetaWithName(
    "description",
    "A playful avatar generator for the modern age.",
  ),
  MetaWithName("twitter:card", "summary"),
  MetaWithName("twitter:site", "@mediazvn"),
  MetaWithName("twitter:title", "Avatar by MediaZ"),
  MetaWithName(
    "twitter:image",
    "https://Avatar.MediaZ.club/web-preview-1x1.png",
  ),
  MetaWithName(
    "twitter:description",
    "A playful avatar generator for the modern age.",
  ),
  MetaWithName(
    "keywords",
    "Avatar, Avatar Generator, Avatar, MediaZ, Avatars",
  ),
  MetaWithProperty("fb:app_id", "292869531545861"),
  MetaWithProperty("og:type", "website"),
  MetaWithProperty(
    "og:image",
    "https://Avatar.MediaZ.club/web-preview.png",
  ),
  MetaWithProperty("og:title", "Avatar by MediaZ"),
  MetaWithProperty("og:url", "https://avatar.mediaz.club"),
  MetaWithProperty(
    "og:description",
    "A playful avatar generator for the modern age.",
  ),
|];

let link = [|{rel: "canonical", href: "https://avatar.mediaz.club"}|];

let metaToHelmet = (item: metaItem) =>
  switch (item) {
  | MetaWithName(name, content) => finalMetaItem(~name, ~content, ())
  | MetaWithProperty(property, content) =>
    finalMetaItem(~property, ~content, ())
  };

[@react.component]
let make = (~children: ReasonReact.reactElement) => {
  let data: queryResponseType =
    useStaticQuery(
      [%bs.raw
        {|
                graphql`
                    query SiteTitleQuery {
                      site {
                        siteMetadata {
                          title
                        }
                      }
                    }
                  `
                |}
      ],
    );

  <>
    <Helmet
      title={data.site.siteMetadata.title}
      link
      meta={meta |> Array.map(metaToHelmet)}>
      <html lang="en" />
    </Helmet>
    children
  </>;
};

let default = make;
