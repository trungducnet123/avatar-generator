module.exports = {
  siteMetadata: {
    title:
      'Avatar by MediaZ | A playful avatar generator for the modern age.',
  },
  plugins: [
    'gatsby-plugin-react-helmet',
    {
      resolve: `gatsby-plugin-manifest`,
      options: {
        name: 'persona-avatar-generator-MediaZ',
        short_name: 'avatar-generator',
        start_url: '/',
        background_color: '#5a45ff',
        theme_color: '#5a45ff',
        display: 'minimal-ui',
        icon: 'src/images/favicon.png',
      },
    },
    {
      resolve: `gatsby-plugin-google-analytics`,
      options: {
        trackingId: '',
        respectDNT: true,
      },
    },
    {
      resolve: 'gatsby-plugin-react-svg',
      options: {
        rule: {
          include: /avatars/,
        },
      },
    },
    `gatsby-transformer-json`,
    {
      resolve: `gatsby-source-filesystem`,
      options: {
        typeName: 'Config',
        path: `./src/data/`,
      },
    },
    'gatsby-plugin-offline',
    `gatsby-plugin-netlify`,
  ],
}
